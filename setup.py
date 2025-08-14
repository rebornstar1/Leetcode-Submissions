#!/usr/bin/env python3
"""
Setup Script for Facebook Group Notification to Call Automation Tool

This script automates the installation and configuration of the monitoring system.
"""

import os
import sys
import json
import subprocess
import shutil
import getpass
from pathlib import Path
from typing import Dict, Optional

class FacebookMonitorSetup:
    """Setup and configuration manager"""
    
    def __init__(self):
        """Initialize the setup"""
        self.base_dir = Path.cwd()
        self.venv_dir = self.base_dir / "venv"
        self.logs_dir = self.base_dir / "logs"
        self.data_dir = self.base_dir / "data"
        self.config_file = self.base_dir / "config.json"
        self.env_file = self.base_dir / ".env"
    
    def print_header(self):
        """Print setup header"""
        print("=" * 60)
        print("Facebook Group Notification to Call Automation Tool")
        print("Setup and Configuration Script")
        print("=" * 60)
        print()
    
    def check_python_version(self) -> bool:
        """Check if Python version is compatible"""
        print("Checking Python version...")
        
        if sys.version_info < (3, 7):
            print("❌ Error: Python 3.7 or higher is required")
            print(f"Current version: {sys.version}")
            return False
        
        print(f"✅ Python {sys.version.split()[0]} is compatible")
        return True
    
    def create_virtual_environment(self) -> bool:
        """Create Python virtual environment"""
        print("Creating virtual environment...")
        
        try:
            if self.venv_dir.exists():
                print("Virtual environment already exists, removing...")
                shutil.rmtree(self.venv_dir)
            
            subprocess.run([sys.executable, "-m", "venv", str(self.venv_dir)], 
                         check=True, capture_output=True)
            
            print("✅ Virtual environment created successfully")
            return True
            
        except subprocess.CalledProcessError as e:
            print(f"❌ Error creating virtual environment: {e}")
            return False
    
    def install_dependencies(self) -> bool:
        """Install required Python packages"""
        print("Installing dependencies...")
        
        # Determine pip path
        if os.name == 'nt':  # Windows
            pip_path = self.venv_dir / "Scripts" / "pip"
        else:  # Unix/Linux/macOS
            pip_path = self.venv_dir / "bin" / "pip"
        
        try:
            # Upgrade pip first
            subprocess.run([str(pip_path), "install", "--upgrade", "pip"], 
                         check=True, capture_output=True)
            
            # Install requirements
            subprocess.run([str(pip_path), "install", "-r", "requirements.txt"], 
                         check=True, capture_output=True)
            
            print("✅ Dependencies installed successfully")
            return True
            
        except subprocess.CalledProcessError as e:
            print(f"❌ Error installing dependencies: {e}")
            return False
    
    def create_directories(self):
        """Create necessary directories"""
        print("Creating directories...")
        
        directories = [self.logs_dir, self.data_dir]
        
        for directory in directories:
            directory.mkdir(exist_ok=True)
            print(f"✅ Created directory: {directory}")
    
    def setup_configuration(self) -> bool:
        """Set up configuration files"""
        print("\nSetting up configuration...")
        
        # Load default config
        if not self.config_file.exists():
            print("❌ config.json not found")
            return False
        
        try:
            with open(self.config_file, 'r') as f:
                config = json.load(f)
        except Exception as e:
            print(f"❌ Error loading config.json: {e}")
            return False
        
        # Interactive configuration
        print("\nConfiguring Facebook groups...")
        groups = self._configure_facebook_groups()
        config['facebook']['groups'] = groups
        
        # Configure monitoring interval
        interval = self._get_input("Check interval in minutes", "30", int)
        config['facebook']['check_interval_minutes'] = interval
        
        # Save updated config
        try:
            with open(self.config_file, 'w') as f:
                json.dump(config, f, indent=2)
            print("✅ Configuration saved")
        except Exception as e:
            print(f"❌ Error saving configuration: {e}")
            return False
        
        return True
    
    def _configure_facebook_groups(self) -> list:
        """Configure Facebook groups interactively"""
        groups = []
        
        print("Enter Facebook groups to monitor (press Enter with empty name to finish):")
        
        while True:
            name = input(f"Group {len(groups) + 1} name (or Enter to finish): ").strip()
            if not name:
                break
            
            url = input(f"Group '{name}' URL: ").strip()
            if not url:
                print("❌ URL is required")
                continue
            
            enabled = self._get_yes_no("Enable monitoring for this group?", True)
            
            groups.append({
                "name": name,
                "url": url,
                "enabled": enabled,
                "last_check": None,
                "last_post_id": None
            })
            
            print(f"✅ Added group: {name}")
        
        if not groups:
            # Add default example
            groups.append({
                "name": "Example Group",
                "url": "https://www.facebook.com/groups/example",
                "enabled": False,
                "last_check": None,
                "last_post_id": None
            })
            print("⚠️  Added example group (disabled). Please update config.json with real groups.")
        
        return groups
    
    def setup_environment(self) -> bool:
        """Set up environment variables"""
        print("\nSetting up environment variables...")
        
        # Check if .env already exists
        if self.env_file.exists():
            overwrite = self._get_yes_no("Environment file already exists. Overwrite?", False)
            if not overwrite:
                print("Skipping environment setup")
                return True
        
        env_vars = {}
        
        # Twilio configuration
        print("\nTwilio Configuration (get from https://console.twilio.com/):")
        print("Note: Twilio provides $15 free credit for new accounts")
        
        account_sid = input("Twilio Account SID (optional): ").strip()
        if account_sid:
            env_vars['TWILIO_ACCOUNT_SID'] = account_sid
            
            auth_token = getpass.getpass("Twilio Auth Token: ").strip()
            env_vars['TWILIO_AUTH_TOKEN'] = auth_token
            
            twilio_phone = input("Twilio Phone Number (e.g., +1234567890): ").strip()
            env_vars['TWILIO_PHONE_NUMBER'] = twilio_phone
        
        # Target phone number
        your_phone = input("Your phone number to receive calls (e.g., +1234567890): ").strip()
        if your_phone:
            env_vars['YOUR_PHONE_NUMBER'] = your_phone
        
        # Facebook credentials (optional)
        print("\nFacebook Credentials (optional, for private groups):")
        fb_email = input("Facebook email (optional): ").strip()
        if fb_email:
            env_vars['FACEBOOK_EMAIL'] = fb_email
            
            fb_password = getpass.getpass("Facebook password: ").strip()
            if fb_password:
                env_vars['FACEBOOK_PASSWORD'] = fb_password
        
        # Write environment file
        try:
            with open(self.env_file, 'w') as f:
                for key, value in env_vars.items():
                    f.write(f"{key}={value}\n")
            
            print("✅ Environment file created")
            return True
            
        except Exception as e:
            print(f"❌ Error creating environment file: {e}")
            return False
    
    def test_installation(self) -> bool:
        """Test the installation"""
        print("\nTesting installation...")
        
        # Determine python path
        if os.name == 'nt':  # Windows
            python_path = self.venv_dir / "Scripts" / "python"
        else:  # Unix/Linux/macOS
            python_path = self.venv_dir / "bin" / "python"
        
        try:
            # Test imports
            test_script = """
import sys
try:
    from facebook_monitor import FacebookMonitor
    from call_service import CallService
    from scheduler import MonitorScheduler
    print("✅ All modules imported successfully")
    
    # Test call service
    import json
    with open('config.json', 'r') as f:
        config = json.load(f)
    
    call_service = CallService(config)
    results = call_service.test_connection()
    
    for service, status in results.items():
        print(f"Service {service}: {'✅' if status else '❌'}")
    
    print("✅ Installation test completed")
    
except Exception as e:
    print(f"❌ Installation test failed: {e}")
    sys.exit(1)
"""
            
            with open("test_install.py", "w") as f:
                f.write(test_script)
            
            result = subprocess.run([str(python_path), "test_install.py"], 
                                  capture_output=True, text=True)
            
            # Clean up test file
            os.remove("test_install.py")
            
            if result.returncode == 0:
                print(result.stdout)
                return True
            else:
                print("❌ Installation test failed:")
                print(result.stderr)
                return False
                
        except Exception as e:
            print(f"❌ Error running installation test: {e}")
            return False
    
    def create_run_scripts(self):
        """Create convenient run scripts"""
        print("Creating run scripts...")
        
        # Determine python path
        if os.name == 'nt':  # Windows
            python_path = self.venv_dir / "Scripts" / "python"
            script_ext = ".bat"
        else:  # Unix/Linux/macOS
            python_path = self.venv_dir / "bin" / "python"
            script_ext = ".sh"
        
        scripts = {
            f"run_monitor{script_ext}": f"{python_path} facebook_monitor.py",
            f"run_scheduler{script_ext}": f"{python_path} scheduler.py",
            f"run_once{script_ext}": f"{python_path} scheduler.py --once",
            f"test_call{script_ext}": f"{python_path} call_service.py"
        }
        
        for script_name, command in scripts.items():
            script_path = self.base_dir / script_name
            
            if os.name == 'nt':  # Windows batch file
                content = f"@echo off\n{command}\npause\n"
            else:  # Unix shell script
                content = f"#!/bin/bash\n{command}\n"
            
            try:
                with open(script_path, 'w') as f:
                    f.write(content)
                
                # Make executable on Unix systems
                if os.name != 'nt':
                    os.chmod(script_path, 0o755)
                
                print(f"✅ Created script: {script_name}")
                
            except Exception as e:
                print(f"❌ Error creating script {script_name}: {e}")
    
    def print_usage_instructions(self):
        """Print usage instructions"""
        print("\n" + "=" * 60)
        print("Setup completed successfully!")
        print("=" * 60)
        print()
        print("Usage Instructions:")
        print()
        print("1. Update configuration:")
        print("   - Edit config.json to configure Facebook groups")
        print("   - Edit .env to set your credentials")
        print()
        print("2. Run the monitor:")
        if os.name == 'nt':
            print("   - Double-click run_scheduler.bat for continuous monitoring")
            print("   - Double-click run_once.bat for single check")
            print("   - Double-click test_call.bat to test calling service")
        else:
            print("   - ./run_scheduler.sh for continuous monitoring")
            print("   - ./run_once.sh for single check")
            print("   - ./test_call.sh to test calling service")
        print()
        print("3. Monitor logs:")
        print("   - Check logs/facebook_monitor.log for activity")
        print("   - Check logs/facebook_monitor_scheduler.log for scheduler activity")
        print()
        print("4. Twilio Setup (for phone calls):")
        print("   - Sign up at https://www.twilio.com/")
        print("   - Get $15 free credit")
        print("   - Update .env with your Twilio credentials")
        print()
        print("For help, check the README.md file")
        print()
    
    def _get_input(self, prompt: str, default: str = "", input_type=str):
        """Get user input with default value"""
        full_prompt = f"{prompt}"
        if default:
            full_prompt += f" [{default}]"
        full_prompt += ": "
        
        value = input(full_prompt).strip()
        if not value and default:
            value = default
        
        try:
            return input_type(value) if value else None
        except ValueError:
            print(f"Invalid input, using default: {default}")
            return input_type(default) if default else None
    
    def _get_yes_no(self, prompt: str, default: bool = True) -> bool:
        """Get yes/no input from user"""
        default_text = "Y/n" if default else "y/N"
        response = input(f"{prompt} [{default_text}]: ").strip().lower()
        
        if not response:
            return default
        
        return response in ['y', 'yes', 'true', '1']
    
    def run_setup(self) -> bool:
        """Run the complete setup process"""
        self.print_header()
        
        # Check Python version
        if not self.check_python_version():
            return False
        
        # Create virtual environment
        if not self.create_virtual_environment():
            return False
        
        # Install dependencies
        if not self.install_dependencies():
            return False
        
        # Create directories
        self.create_directories()
        
        # Setup configuration
        if not self.setup_configuration():
            return False
        
        # Setup environment
        if not self.setup_environment():
            return False
        
        # Test installation
        if not self.test_installation():
            print("⚠️  Installation test failed, but setup may still work")
        
        # Create run scripts
        self.create_run_scripts()
        
        # Print instructions
        self.print_usage_instructions()
        
        return True

def main():
    """Main setup function"""
    setup = FacebookMonitorSetup()
    
    try:
        success = setup.run_setup()
        sys.exit(0 if success else 1)
    except KeyboardInterrupt:
        print("\n❌ Setup interrupted by user")
        sys.exit(1)
    except Exception as e:
        print(f"\n❌ Unexpected error during setup: {e}")
        sys.exit(1)

if __name__ == "__main__":
    main()