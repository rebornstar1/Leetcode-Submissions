#!/usr/bin/env python3
"""
Facebook Group Notification Monitor

This script monitors Facebook groups for new posts and notifications,
triggering phone calls when new activity is detected.
"""

import os
import json
import time
import logging
import requests
from datetime import datetime, timedelta
from typing import List, Dict, Optional
from bs4 import BeautifulSoup
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.common.exceptions import TimeoutException, WebDriverException
from webdriver_manager.chrome import ChromeDriverManager
from dotenv import load_dotenv

from call_service import CallService

# Load environment variables
load_dotenv()

class FacebookMonitor:
    """Main class for monitoring Facebook groups"""
    
    def __init__(self, config_file: str = "config.json"):
        """Initialize the Facebook monitor"""
        self.config = self._load_config(config_file)
        self.state_file = self.config['state']['file']
        self.state = self._load_state()
        self.call_service = CallService(self.config)
        self.logger = self._setup_logging()
        self.driver = None
        
    def _load_config(self, config_file: str) -> Dict:
        """Load configuration from JSON file"""
        try:
            with open(config_file, 'r') as f:
                return json.load(f)
        except FileNotFoundError:
            self.logger.error(f"Configuration file {config_file} not found")
            raise
        except json.JSONDecodeError as e:
            self.logger.error(f"Error parsing configuration file: {e}")
            raise
    
    def _load_state(self) -> Dict:
        """Load monitoring state from file"""
        if os.path.exists(self.state_file):
            try:
                with open(self.state_file, 'r') as f:
                    return json.load(f)
            except (json.JSONDecodeError, FileNotFoundError):
                self.logger.warning("Could not load state file, starting fresh")
        
        return {
            "last_check": None,
            "groups": {},
            "notifications_sent": []
        }
    
    def _save_state(self):
        """Save current state to file"""
        os.makedirs(os.path.dirname(self.state_file), exist_ok=True)
        try:
            with open(self.state_file, 'w') as f:
                json.dump(self.state, f, indent=2, default=str)
            self.logger.debug("State saved successfully")
        except Exception as e:
            self.logger.error(f"Error saving state: {e}")
    
    def _setup_logging(self) -> logging.Logger:
        """Set up logging configuration"""
        logger = logging.getLogger(__name__)
        logger.setLevel(getattr(logging, self.config['logging']['level']))
        
        # Create logs directory if it doesn't exist
        log_file = self.config['logging']['file']
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
                '%(levelname)s - %(message)s'
            )
            console_handler.setFormatter(console_formatter)
            logger.addHandler(console_handler)
        
        return logger
    
    def _setup_driver(self) -> webdriver.Chrome:
        """Set up Chrome WebDriver with appropriate options"""
        chrome_options = Options()
        chrome_options.add_argument("--headless")  # Run in background
        chrome_options.add_argument("--no-sandbox")
        chrome_options.add_argument("--disable-dev-shm-usage")
        chrome_options.add_argument("--disable-gpu")
        chrome_options.add_argument("--window-size=1920,1080")
        chrome_options.add_argument(f"--user-agent={self.config['facebook']['user_agent']}")
        
        try:
            driver = webdriver.Chrome(
                ChromeDriverManager().install(),
                options=chrome_options
            )
            return driver
        except Exception as e:
            self.logger.error(f"Error setting up Chrome driver: {e}")
            raise
    
    def _login_to_facebook(self, driver: webdriver.Chrome) -> bool:
        """Login to Facebook if credentials are provided"""
        email = os.getenv('FACEBOOK_EMAIL')
        password = os.getenv('FACEBOOK_PASSWORD')
        
        if not email or not password:
            self.logger.info("No Facebook credentials provided, proceeding without login")
            return False
        
        try:
            self.logger.info("Logging into Facebook...")
            driver.get("https://www.facebook.com/login")
            
            # Wait for login form
            WebDriverWait(driver, 10).until(
                EC.presence_of_element_located((By.ID, "email"))
            )
            
            # Enter credentials
            email_field = driver.find_element(By.ID, "email")
            password_field = driver.find_element(By.ID, "pass")
            
            email_field.send_keys(email)
            password_field.send_keys(password)
            
            # Click login button
            login_button = driver.find_element(By.NAME, "login")
            login_button.click()
            
            # Wait for redirect to home page
            WebDriverWait(driver, 15).until(
                lambda d: "facebook.com" in d.current_url and "login" not in d.current_url
            )
            
            self.logger.info("Successfully logged into Facebook")
            return True
            
        except TimeoutException:
            self.logger.error("Timeout during Facebook login")
            return False
        except Exception as e:
            self.logger.error(f"Error during Facebook login: {e}")
            return False
    
    def _check_group(self, group: Dict) -> List[Dict]:
        """Check a specific Facebook group for new posts"""
        if not group.get('enabled', True):
            return []
        
        group_url = group['url']
        group_name = group['name']
        
        self.logger.info(f"Checking group: {group_name}")
        
        try:
            self.driver.get(group_url)
            time.sleep(5)  # Wait for page to load
            
            # Look for posts
            posts = []
            
            # Try different selectors for posts
            post_selectors = [
                '[data-pagelet="FeedUnit_0"]',
                '[role="article"]',
                '[data-testid="fbfeed_story"]',
                '.userContentWrapper'
            ]
            
            for selector in post_selectors:
                try:
                    post_elements = self.driver.find_elements(By.CSS_SELECTOR, selector)
                    if post_elements:
                        self.logger.debug(f"Found {len(post_elements)} posts using selector: {selector}")
                        break
                except:
                    continue
            else:
                self.logger.warning(f"Could not find posts in group: {group_name}")
                return []
            
            # Extract post information
            for element in post_elements[:5]:  # Check only first 5 posts
                try:
                    post_text = element.text[:200] if element.text else ""
                    post_time = self._extract_post_time(element)
                    
                    if post_time and self._is_new_post(group_name, post_time, post_text):
                        posts.append({
                            'group': group_name,
                            'text': post_text,
                            'time': post_time,
                            'url': group_url
                        })
                except Exception as e:
                    self.logger.debug(f"Error processing post element: {e}")
                    continue
            
            # Update group state
            if group_name not in self.state['groups']:
                self.state['groups'][group_name] = {}
            
            self.state['groups'][group_name]['last_check'] = datetime.now().isoformat()
            
            return posts
            
        except Exception as e:
            self.logger.error(f"Error checking group {group_name}: {e}")
            return []
    
    def _extract_post_time(self, post_element) -> Optional[datetime]:
        """Extract timestamp from post element"""
        try:
            # Look for time elements
            time_selectors = [
                'time',
                '[data-testid="story-subtitle"] a',
                '.timestampContent',
                'abbr'
            ]
            
            for selector in time_selectors:
                try:
                    time_elements = post_element.find_elements(By.CSS_SELECTOR, selector)
                    for time_elem in time_elements:
                        # Try to get datetime from various attributes
                        for attr in ['datetime', 'data-utime', 'title']:
                            time_value = time_elem.get_attribute(attr)
                            if time_value:
                                return self._parse_time(time_value)
                except:
                    continue
            
            return None
            
        except Exception as e:
            self.logger.debug(f"Error extracting post time: {e}")
            return None
    
    def _parse_time(self, time_str: str) -> Optional[datetime]:
        """Parse time string to datetime object"""
        try:
            # Try ISO format first
            if 'T' in time_str:
                return datetime.fromisoformat(time_str.replace('Z', '+00:00'))
            
            # Try Unix timestamp
            if time_str.isdigit():
                return datetime.fromtimestamp(int(time_str))
            
            # Handle relative time strings (simplified)
            now = datetime.now()
            time_str_lower = time_str.lower()
            
            if 'minute' in time_str_lower:
                minutes = int(''.join(filter(str.isdigit, time_str_lower)))
                return now - timedelta(minutes=minutes)
            elif 'hour' in time_str_lower:
                hours = int(''.join(filter(str.isdigit, time_str_lower)))
                return now - timedelta(hours=hours)
            
            return None
            
        except Exception as e:
            self.logger.debug(f"Error parsing time string '{time_str}': {e}")
            return None
    
    def _is_new_post(self, group_name: str, post_time: datetime, post_text: str) -> bool:
        """Check if a post is new (not previously processed)"""
        if not post_time:
            return False
        
        # Check if we've seen this post before
        notification_key = f"{group_name}:{post_time.isoformat()}:{hash(post_text[:50])}"
        
        if notification_key in self.state.get('notifications_sent', []):
            return False
        
        # Check if post is within monitoring window
        check_interval = timedelta(minutes=self.config['facebook']['check_interval_minutes'])
        duplicate_prevention = timedelta(hours=self.config['notifications']['duplicate_prevention_hours'])
        
        if post_time > datetime.now() - check_interval:
            # Add to processed notifications
            if 'notifications_sent' not in self.state:
                self.state['notifications_sent'] = []
            
            # Keep only recent notifications (prevent memory bloat)
            cutoff_time = datetime.now() - duplicate_prevention
            self.state['notifications_sent'] = [
                n for n in self.state['notifications_sent'] 
                if datetime.fromisoformat(n.split(':')[1]) > cutoff_time
            ]
            
            self.state['notifications_sent'].append(notification_key)
            return True
        
        return False
    
    def monitor_groups(self) -> List[Dict]:
        """Monitor all configured Facebook groups"""
        self.logger.info("Starting Facebook group monitoring...")
        
        new_posts = []
        
        try:
            # Set up WebDriver
            self.driver = self._setup_driver()
            
            # Login if credentials are provided
            if self.config['facebook']['login_required']:
                if not self._login_to_facebook(self.driver):
                    self.logger.error("Facebook login failed, proceeding without login")
            
            # Check each group
            for group in self.config['facebook']['groups']:
                try:
                    posts = self._check_group(group)
                    new_posts.extend(posts)
                    time.sleep(5)  # Rate limiting between groups
                except Exception as e:
                    self.logger.error(f"Error checking group {group.get('name', 'Unknown')}: {e}")
                    continue
            
        except Exception as e:
            self.logger.error(f"Error during monitoring: {e}")
        
        finally:
            # Clean up WebDriver
            if self.driver:
                try:
                    self.driver.quit()
                except:
                    pass
                self.driver = None
        
        # Update state
        self.state['last_check'] = datetime.now().isoformat()
        self._save_state()
        
        self.logger.info(f"Monitoring completed. Found {len(new_posts)} new posts.")
        return new_posts
    
    def process_notifications(self, posts: List[Dict]):
        """Process new posts and trigger notifications"""
        if not posts:
            return
        
        self.logger.info(f"Processing {len(posts)} new posts...")
        
        # Group posts by group for summary
        groups_with_updates = {}
        for post in posts:
            group_name = post['group']
            if group_name not in groups_with_updates:
                groups_with_updates[group_name] = []
            groups_with_updates[group_name].append(post)
        
        # Create notification message
        if len(groups_with_updates) == 1:
            group_name = list(groups_with_updates.keys())[0]
            post_count = len(groups_with_updates[group_name])
            message = f"You have {post_count} new post{'s' if post_count > 1 else ''} in {group_name}"
        else:
            group_count = len(groups_with_updates)
            total_posts = len(posts)
            message = f"You have {total_posts} new posts across {group_count} Facebook groups"
        
        # Trigger phone call
        if self.config['notifications']['enable_calls']:
            try:
                self.call_service.make_call(message)
                self.logger.info("Notification call triggered successfully")
            except Exception as e:
                self.logger.error(f"Error making notification call: {e}")
        
        # Log the posts for debugging
        for post in posts:
            self.logger.info(f"New post in {post['group']}: {post['text'][:100]}...")
    
    def run_once(self):
        """Run monitoring cycle once"""
        try:
            new_posts = self.monitor_groups()
            if new_posts:
                self.process_notifications(new_posts)
            else:
                self.logger.info("No new posts found")
        except Exception as e:
            self.logger.error(f"Error in monitoring cycle: {e}")
    
    def cleanup(self):
        """Clean up resources"""
        if self.driver:
            try:
                self.driver.quit()
            except:
                pass

def main():
    """Main entry point"""
    monitor = FacebookMonitor()
    
    try:
        monitor.run_once()
    except KeyboardInterrupt:
        monitor.logger.info("Monitoring stopped by user")
    except Exception as e:
        monitor.logger.error(f"Unexpected error: {e}")
    finally:
        monitor.cleanup()

if __name__ == "__main__":
    main()