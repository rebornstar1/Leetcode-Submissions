#!/usr/bin/env python3
"""
Call Service Module

Handles phone calls using Twilio and other free calling services.
Provides text-to-speech functionality for notifications.
"""

import os
import logging
import time
from typing import Optional, Dict
from datetime import datetime, timedelta
from twilio.rest import Client
from twilio.base.exceptions import TwilioException
import pyttsx3
from dotenv import load_dotenv

# Load environment variables
load_dotenv()

class CallService:
    """Service for making phone calls and text-to-speech notifications"""
    
    def __init__(self, config: Dict):
        """Initialize the call service"""
        self.config = config
        self.logger = logging.getLogger(__name__)
        
        # Twilio configuration
        self.twilio_sid = os.getenv('TWILIO_ACCOUNT_SID')
        self.twilio_token = os.getenv('TWILIO_AUTH_TOKEN')
        self.twilio_phone = os.getenv('TWILIO_PHONE_NUMBER')
        self.target_phone = os.getenv('YOUR_PHONE_NUMBER')
        
        # Initialize Twilio client
        self.twilio_client = None
        if self.twilio_sid and self.twilio_token:
            try:
                self.twilio_client = Client(self.twilio_sid, self.twilio_token)
                self.logger.info("Twilio client initialized successfully")
            except Exception as e:
                self.logger.error(f"Error initializing Twilio client: {e}")
        else:
            self.logger.warning("Twilio credentials not provided")
        
        # Initialize TTS engine
        self.tts_engine = None
        if self.config['notifications']['enable_tts']:
            try:
                self.tts_engine = pyttsx3.init()
                self._configure_tts()
                self.logger.info("Text-to-speech engine initialized")
            except Exception as e:
                self.logger.error(f"Error initializing TTS engine: {e}")
        
        # Call tracking to prevent spam
        self.recent_calls = []
    
    def _configure_tts(self):
        """Configure text-to-speech settings"""
        if not self.tts_engine:
            return
        
        try:
            # Set speech rate (words per minute)
            self.tts_engine.setProperty('rate', 150)
            
            # Set volume (0.0 to 1.0)
            self.tts_engine.setProperty('volume', 0.8)
            
            # Try to set a clear voice
            voices = self.tts_engine.getProperty('voices')
            if voices:
                # Prefer female voice if available
                for voice in voices:
                    if voice.name and 'female' in voice.name.lower():
                        self.tts_engine.setProperty('voice', voice.id)
                        break
                else:
                    # Use first available voice
                    self.tts_engine.setProperty('voice', voices[0].id)
        
        except Exception as e:
            self.logger.warning(f"Error configuring TTS: {e}")
    
    def _can_make_call(self) -> bool:
        """Check if we can make a call (rate limiting)"""
        now = datetime.now()
        
        # Remove old calls (older than 1 hour)
        self.recent_calls = [
            call_time for call_time in self.recent_calls 
            if now - call_time < timedelta(hours=1)
        ]
        
        # Check if we've made too many calls recently
        max_calls_per_hour = 5  # Reasonable limit
        if len(self.recent_calls) >= max_calls_per_hour:
            self.logger.warning("Rate limit reached for phone calls")
            return False
        
        return True
    
    def _record_call(self):
        """Record that a call was made"""
        self.recent_calls.append(datetime.now())
    
    def make_twilio_call(self, message: str) -> bool:
        """Make a phone call using Twilio"""
        if not self.twilio_client:
            self.logger.error("Twilio client not available")
            return False
        
        if not self.target_phone:
            self.logger.error("Target phone number not configured")
            return False
        
        if not self._can_make_call():
            return False
        
        try:
            # Create TwiML for the call
            twiml_message = f"""
            <Response>
                <Say voice="alice" language="en-US">{message}</Say>
                <Pause length="2"/>
                <Say voice="alice" language="en-US">This message will repeat once more.</Say>
                <Pause length="1"/>
                <Say voice="alice" language="en-US">{message}</Say>
            </Response>
            """
            
            # Make the call
            call = self.twilio_client.calls.create(
                twiml=twiml_message,
                to=self.target_phone,
                from_=self.twilio_phone,
                timeout=30  # Ring for 30 seconds max
            )
            
            self._record_call()
            self.logger.info(f"Twilio call initiated successfully. Call SID: {call.sid}")
            
            # Monitor call status (optional)
            self._monitor_call_status(call.sid)
            
            return True
            
        except TwilioException as e:
            self.logger.error(f"Twilio error making call: {e}")
            return False
        except Exception as e:
            self.logger.error(f"Unexpected error making Twilio call: {e}")
            return False
    
    def _monitor_call_status(self, call_sid: str):
        """Monitor the status of a Twilio call"""
        if not self.twilio_client:
            return
        
        try:
            # Wait a bit for call to start
            time.sleep(5)
            
            call = self.twilio_client.calls(call_sid).fetch()
            self.logger.info(f"Call status: {call.status}")
            
            if call.status == 'failed':
                self.logger.error(f"Call failed. Error: {call.error_message}")
            elif call.status in ['completed', 'busy', 'no-answer']:
                self.logger.info(f"Call {call.status}")
            
        except Exception as e:
            self.logger.warning(f"Error monitoring call status: {e}")
    
    def make_tts_announcement(self, message: str) -> bool:
        """Make a local text-to-speech announcement"""
        if not self.tts_engine:
            self.logger.error("TTS engine not available")
            return False
        
        try:
            self.logger.info("Making TTS announcement")
            self.tts_engine.say(message)
            self.tts_engine.runAndWait()
            return True
            
        except Exception as e:
            self.logger.error(f"Error making TTS announcement: {e}")
            return False
    
    def make_call(self, message: str) -> bool:
        """Make a notification call using available services"""
        success = False
        
        # Use custom message or default
        call_message = message or self.config['notifications']['call_message']
        
        self.logger.info(f"Making notification call: {call_message[:50]}...")
        
        # Try Twilio first
        if self.config['twilio']['enabled'] and self.twilio_client:
            success = self.make_twilio_call(call_message)
            
            if success:
                self.logger.info("Notification call completed via Twilio")
            else:
                self.logger.warning("Twilio call failed, trying alternatives")
        
        # Fallback to TTS if Twilio fails or is not available
        if not success and self.config['notifications']['enable_tts']:
            success = self.make_tts_announcement(call_message)
            
            if success:
                self.logger.info("Notification delivered via TTS")
        
        if not success:
            self.logger.error("All notification methods failed")
        
        return success
    
    def test_connection(self) -> Dict[str, bool]:
        """Test connection to calling services"""
        results = {
            'twilio': False,
            'tts': False
        }
        
        # Test Twilio connection
        if self.twilio_client:
            try:
                # Test by fetching account info
                account = self.twilio_client.api.accounts(self.twilio_sid).fetch()
                if account.status == 'active':
                    results['twilio'] = True
                    self.logger.info("Twilio connection test passed")
                else:
                    self.logger.warning(f"Twilio account status: {account.status}")
            except Exception as e:
                self.logger.error(f"Twilio connection test failed: {e}")
        
        # Test TTS
        if self.tts_engine:
            try:
                # Quick test without audio output
                test_message = "Test"
                results['tts'] = True
                self.logger.info("TTS connection test passed")
            except Exception as e:
                self.logger.error(f"TTS connection test failed: {e}")
        
        return results
    
    def get_twilio_usage(self) -> Dict:
        """Get Twilio account usage information"""
        if not self.twilio_client:
            return {}
        
        try:
            account = self.twilio_client.api.accounts(self.twilio_sid).fetch()
            
            # Get usage for current month
            usage_records = self.twilio_client.usage.records.list(
                category='calls',
                start_date=datetime.now().replace(day=1).date(),
                end_date=datetime.now().date()
            )
            
            total_usage = sum(float(record.usage) for record in usage_records)
            
            return {
                'account_status': account.status,
                'account_sid': account.sid[:8] + '...',  # Partial SID for privacy
                'monthly_call_usage': total_usage,
                'balance': account.balance if hasattr(account, 'balance') else 'Unknown'
            }
            
        except Exception as e:
            self.logger.error(f"Error fetching Twilio usage: {e}")
            return {'error': str(e)}

def main():
    """Test the call service"""
    import json
    
    # Load config
    with open('config.json', 'r') as f:
        config = json.load(f)
    
    # Initialize service
    call_service = CallService(config)
    
    # Test connections
    print("Testing call service connections...")
    results = call_service.test_connection()
    
    for service, status in results.items():
        print(f"{service.capitalize()}: {'✓' if status else '✗'}")
    
    # Get Twilio usage
    if results['twilio']:
        usage = call_service.get_twilio_usage()
        print(f"\nTwilio Usage: {usage}")
    
    # Test call (uncomment to actually make a call)
    # call_service.make_call("This is a test notification from your Facebook monitor.")

if __name__ == "__main__":
    main()