# Leetcode-Submissions

## Facebook Group Notification to Call Automation Tool

A complete implementation of a tool that monitors Facebook groups and triggers phone calls automatically when new activity is detected. This solution is free, automatic, and notifies users about updates in real-time.

### 🚀 Features

- **Real-time Facebook Group Monitoring**: Automatically scrapes and monitors Facebook groups for new posts and activity
- **Automatic Phone Call Notifications**: Triggers phone calls using Twilio when new activity is detected
- **Free Service Integration**: Utilizes Twilio's free tier ($15 credit) for phone calls
- **Text-to-Speech Fallback**: Local TTS announcements when phone calls aren't available
- **Smart Duplicate Prevention**: Avoids sending multiple notifications for the same content
- **Robust Error Handling**: Comprehensive logging and retry mechanisms
- **Easy Configuration**: JSON-based configuration with environment variable support
- **Automated Scheduling**: Configurable monitoring intervals with built-in scheduler
- **Multiple Group Support**: Monitor multiple Facebook groups simultaneously
- **Production Ready**: Complete with logging, state management, and health checks

### 📋 Requirements

- Python 3.7 or higher
- Chrome browser (for web scraping)
- Twilio account (free tier available)
- Internet connection

### 🔧 Quick Setup

1. **Clone and Navigate**
   ```bash
   cd Leetcode-Submissions
   ```

2. **Run Automated Setup**
   ```bash
   python3 setup.py
   ```
   
   The setup script will:
   - Create a virtual environment
   - Install all dependencies
   - Configure Facebook groups
   - Set up Twilio credentials
   - Create run scripts
   - Test the installation

3. **Configure Your Settings**
   
   Update the generated `.env` file with your credentials:
   ```env
   TWILIO_ACCOUNT_SID=your_account_sid
   TWILIO_AUTH_TOKEN=your_auth_token
   TWILIO_PHONE_NUMBER=your_twilio_number
   YOUR_PHONE_NUMBER=+1234567890
   ```

4. **Start Monitoring**
   ```bash
   ./run_scheduler.sh    # Linux/Mac
   run_scheduler.bat     # Windows
   ```

### 📖 Manual Setup (Alternative)

If you prefer manual setup:

1. **Install Dependencies**
   ```bash
   pip install -r requirements.txt
   ```

2. **Configure Groups**
   
   Edit `config.json` to add your Facebook groups:
   ```json
   {
     "facebook": {
       "groups": [
         {
           "name": "Your Group Name",
           "url": "https://www.facebook.com/groups/yourgroupname",
           "enabled": true
         }
       ]
     }
   }
   ```

3. **Set Environment Variables**
   
   Copy `.env.example` to `.env` and fill in your details.

4. **Run the Monitor**
   ```bash
   python facebook_monitor.py    # Single run
   python scheduler.py           # Continuous monitoring
   python scheduler.py --once    # Single check
   ```

### 🔑 Twilio Setup

1. **Create Free Account**
   - Go to [Twilio](https://www.twilio.com/)
   - Sign up for a free account
   - Get $15 in free credits

2. **Get Credentials**
   - Note your Account SID
   - Note your Auth Token
   - Get a Twilio phone number

3. **Update Configuration**
   - Add credentials to `.env` file
   - Test with `python call_service.py`

### 📁 Project Structure

```
├── facebook_monitor.py     # Core monitoring logic
├── call_service.py         # Phone call and TTS service
├── scheduler.py           # Automated scheduling system
├── setup.py              # Automated installation script
├── config.json           # Configuration settings
├── requirements.txt      # Python dependencies
├── .env.example         # Environment template
├── README.md           # This file
├── logs/              # Log files directory
├── data/             # State and data files
└── venv/            # Virtual environment (created by setup)
```

### 🎛️ Configuration Options

#### Facebook Settings (`config.json`)
```json
{
  "facebook": {
    "groups": [...],
    "check_interval_minutes": 30,
    "login_required": false,
    "user_agent": "..."
  }
}
```

#### Notification Settings
```json
{
  "notifications": {
    "enable_calls": true,
    "enable_tts": true,
    "call_message": "Custom message",
    "duplicate_prevention_hours": 1
  }
}
```

#### Twilio Settings
```json
{
  "twilio": {
    "enabled": true,
    "call_duration_seconds": 30,
    "retry_attempts": 3
  }
}
```

### 🚦 Usage Examples

#### Monitor Once
```bash
python scheduler.py --once
```

#### Continuous Monitoring
```bash
python scheduler.py
```

#### Test Call Service
```bash
python call_service.py
```

#### Check Status
```bash
python scheduler.py --status
```

### 📊 Monitoring and Logs

- **Activity Logs**: `logs/facebook_monitor.log`
- **Scheduler Logs**: `logs/facebook_monitor_scheduler.log`
- **State File**: `data/state.json`
- **Configuration**: `config.json`

### 🔧 Troubleshooting

#### Common Issues

1. **"Chrome driver not found"**
   ```bash
   # The setup script handles this automatically
   # If manual installation needed:
   pip install webdriver-manager
   ```

2. **"Twilio credentials invalid"**
   - Verify Account SID and Auth Token
   - Check Twilio phone number format
   - Ensure account is active

3. **"Facebook access denied"**
   - Facebook may block automated access
   - Try adjusting user agent in config
   - Consider using Facebook credentials for private groups

4. **"No new posts detected"**
   - Check if groups are public
   - Verify group URLs are correct
   - Check log files for detailed errors

#### Debug Mode

Enable debug logging in `config.json`:
```json
{
  "logging": {
    "level": "DEBUG"
  }
}
```

### 🔒 Privacy and Security

- **Credentials**: Store sensitive data in `.env` file (not committed to git)
- **Rate Limiting**: Built-in delays to respect Facebook's terms
- **Local Processing**: All monitoring runs locally on your machine
- **Minimal Data**: Only stores necessary state information

### 📝 Customization

#### Adding New Notification Methods

Extend `call_service.py`:
```python
def make_custom_notification(self, message: str) -> bool:
    # Your custom notification logic
    pass
```

#### Custom Post Filtering

Modify `facebook_monitor.py`:
```python
def _is_new_post(self, group_name: str, post_time: datetime, post_text: str) -> bool:
    # Add custom filtering logic
    if "keyword" in post_text.lower():
        return True
    return super()._is_new_post(group_name, post_time, post_text)
```

### 🤝 Contributing

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test thoroughly
5. Submit a pull request

### 📄 License

This project is part of the Leetcode-Submissions repository. Use responsibly and respect Facebook's terms of service.

### ⚠️ Disclaimer

- This tool is for educational and personal use
- Respect Facebook's terms of service and rate limits
- Use responsibly and don't spam
- The authors are not responsible for any misuse

### 🆘 Support

For issues and questions:
1. Check the troubleshooting section
2. Review log files for errors
3. Open an issue in the repository
4. Ensure you're using the latest version

---

*Happy monitoring! 📱📞*