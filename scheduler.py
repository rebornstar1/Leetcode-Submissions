#!/usr/bin/env python3
"""
Facebook Monitor Scheduler

Automates periodic checking of Facebook groups and manages the monitoring process.
"""

import os
import json
import time
import logging
import signal
import sys
from datetime import datetime, timedelta
from typing import Dict, Optional
import schedule
from facebook_monitor import FacebookMonitor
from call_service import CallService

class MonitorScheduler:
    """Scheduler for automated Facebook group monitoring"""
    
    def __init__(self, config_file: str = "config.json"):
        """Initialize the scheduler"""
        self.config = self._load_config(config_file)
        self.monitor = FacebookMonitor(config_file)
        self.logger = self._setup_logging()
        self.running = False
        self.last_run_time = None
        
        # Set up signal handlers for graceful shutdown
        signal.signal(signal.SIGINT, self._signal_handler)
        signal.signal(signal.SIGTERM, self._signal_handler)
    
    def _load_config(self, config_file: str) -> Dict:
        """Load configuration from JSON file"""
        try:
            with open(config_file, 'r') as f:
                return json.load(f)
        except FileNotFoundError:
            print(f"Configuration file {config_file} not found")
            sys.exit(1)
        except json.JSONDecodeError as e:
            print(f"Error parsing configuration file: {e}")
            sys.exit(1)
    
    def _setup_logging(self) -> logging.Logger:
        """Set up logging for the scheduler"""
        logger = logging.getLogger('scheduler')
        logger.setLevel(getattr(logging, self.config['logging']['level']))
        
        # Create logs directory if it doesn't exist
        log_file = self.config['logging']['file'].replace('.log', '_scheduler.log')
        os.makedirs(os.path.dirname(log_file), exist_ok=True)
        
        # File handler
        file_handler = logging.FileHandler(log_file)
        file_formatter = logging.Formatter(
            '%(asctime)s - %(name)s - %(levelname)s - %(message)s'
        )
        file_handler.setFormatter(file_formatter)
        logger.addHandler(file_handler)
        
        # Console handler
        if self.config['logging']['console_output']:
            console_handler = logging.StreamHandler()
            console_formatter = logging.Formatter(
                '%(asctime)s - %(levelname)s - %(message)s'
            )
            console_handler.setFormatter(console_formatter)
            logger.addHandler(console_handler)
        
        return logger
    
    def _signal_handler(self, signum, frame):
        """Handle shutdown signals gracefully"""
        self.logger.info(f"Received signal {signum}, shutting down gracefully...")
        self.running = False
    
    def _run_monitoring_cycle(self):
        """Run a single monitoring cycle"""
        try:
            self.logger.info("Starting scheduled monitoring cycle")
            start_time = datetime.now()
            
            # Run the monitor
            self.monitor.run_once()
            
            # Update last run time
            self.last_run_time = start_time
            
            # Calculate execution time
            execution_time = (datetime.now() - start_time).total_seconds()
            self.logger.info(f"Monitoring cycle completed in {execution_time:.2f} seconds")
            
        except Exception as e:
            self.logger.error(f"Error in monitoring cycle: {e}")
    
    def _check_service_health(self) -> bool:
        """Check the health of required services"""
        try:
            # Test call service connectivity
            call_service = CallService(self.config)
            connection_results = call_service.test_connection()
            
            # Log service status
            for service, status in connection_results.items():
                status_text = "OK" if status else "FAILED"
                self.logger.info(f"Service {service}: {status_text}")
            
            # Check if at least one notification method is available
            if not any(connection_results.values()):
                self.logger.warning("No notification services are available")
                return False
            
            return True
            
        except Exception as e:
            self.logger.error(f"Error checking service health: {e}")
            return False
    
    def setup_schedule(self):
        """Set up the monitoring schedule"""
        if not self.config['scheduler']['enabled']:
            self.logger.info("Scheduler is disabled in configuration")
            return
        
        interval_minutes = self.config['facebook']['check_interval_minutes']
        
        # Schedule monitoring
        schedule.every(interval_minutes).minutes.do(self._run_monitoring_cycle)
        
        # Schedule health checks every hour
        schedule.every().hour.do(self._check_service_health)
        
        self.logger.info(f"Scheduled monitoring every {interval_minutes} minutes")
        self.logger.info("Scheduled health checks every hour")
    
    def run_startup_tasks(self):
        """Run tasks on startup"""
        self.logger.info("Running startup tasks...")
        
        # Check service health
        if not self._check_service_health():
            self.logger.warning("Some services are not available")
        
        # Run initial monitoring if configured
        if self.config['scheduler']['run_on_startup']:
            self.logger.info("Running initial monitoring cycle")
            self._run_monitoring_cycle()
    
    def start(self):
        """Start the scheduler"""
        self.logger.info("Starting Facebook Monitor Scheduler")
        
        # Run startup tasks
        self.run_startup_tasks()
        
        # Set up schedule
        self.setup_schedule()
        
        # Main loop
        self.running = True
        self.logger.info("Scheduler started. Press Ctrl+C to stop.")
        
        try:
            while self.running:
                schedule.run_pending()
                time.sleep(30)  # Check every 30 seconds
                
        except KeyboardInterrupt:
            self.logger.info("Scheduler stopped by user")
        
        self.cleanup()
    
    def run_once(self):
        """Run monitoring once and exit"""
        self.logger.info("Running single monitoring cycle")
        
        # Check service health first
        self._check_service_health()
        
        # Run monitoring
        self._run_monitoring_cycle()
        
        self.logger.info("Single cycle completed")
    
    def cleanup(self):
        """Clean up resources"""
        self.logger.info("Cleaning up scheduler resources")
        
        try:
            if hasattr(self.monitor, 'cleanup'):
                self.monitor.cleanup()
        except Exception as e:
            self.logger.error(f"Error during cleanup: {e}")
        
        self.logger.info("Scheduler shutdown complete")
    
    def get_status(self) -> Dict:
        """Get scheduler status information"""
        return {
            'running': self.running,
            'last_run': self.last_run_time.isoformat() if self.last_run_time else None,
            'next_run': self._get_next_scheduled_run(),
            'config': {
                'interval_minutes': self.config['facebook']['check_interval_minutes'],
                'enabled': self.config['scheduler']['enabled'],
                'run_on_startup': self.config['scheduler']['run_on_startup']
            }
        }
    
    def _get_next_scheduled_run(self) -> Optional[str]:
        """Get the next scheduled run time"""
        try:
            next_run = schedule.next_run()
            return next_run.isoformat() if next_run else None
        except Exception:
            return None

def main():
    """Main entry point"""
    import argparse
    
    parser = argparse.ArgumentParser(description='Facebook Group Monitor Scheduler')
    parser.add_argument('--once', action='store_true', 
                       help='Run monitoring once and exit')
    parser.add_argument('--config', default='config.json',
                       help='Configuration file path')
    parser.add_argument('--status', action='store_true',
                       help='Show scheduler status')
    
    args = parser.parse_args()
    
    # Initialize scheduler
    scheduler = MonitorScheduler(args.config)
    
    if args.status:
        # Show status
        status = scheduler.get_status()
        print("Scheduler Status:")
        print(f"  Running: {status['running']}")
        print(f"  Last Run: {status['last_run'] or 'Never'}")
        print(f"  Next Run: {status['next_run'] or 'Not scheduled'}")
        print(f"  Interval: {status['config']['interval_minutes']} minutes")
        print(f"  Enabled: {status['config']['enabled']}")
        return
    
    if args.once:
        # Run once and exit
        scheduler.run_once()
    else:
        # Start continuous monitoring
        scheduler.start()

if __name__ == "__main__":
    main()