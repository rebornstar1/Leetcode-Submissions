#!/usr/bin/env python3
"""
Installation Validator for Facebook Group Notification Tool

Checks installation completeness without requiring external dependencies.
"""

import os
import json
import sys

def check_python_version():
    """Check Python version compatibility"""
    print("🐍 Python Version Check:")
    version = sys.version_info
    if version >= (3, 7):
        print(f"   ✅ Python {version.major}.{version.minor}.{version.micro} (Compatible)")
        return True
    else:
        print(f"   ❌ Python {version.major}.{version.minor}.{version.micro} (Requires 3.7+)")
        return False

def check_required_files():
    """Check if all required files exist"""
    print("\n📁 Required Files Check:")
    
    required_files = {
        'facebook_monitor.py': 'Core monitoring script',
        'call_service.py': 'Calling service',
        'scheduler.py': 'Scheduling system',
        'setup.py': 'Installation script',
        'config.json': 'Configuration file',
        'requirements.txt': 'Dependencies list',
        '.env.example': 'Environment template',
        'README.md': 'Documentation',
        '.gitignore': 'Git exclusions'
    }
    
    all_present = True
    for filename, description in required_files.items():
        if os.path.exists(filename):
            print(f"   ✅ {filename:<20} - {description}")
        else:
            print(f"   ❌ {filename:<20} - {description} (MISSING)")
            all_present = False
    
    return all_present

def check_configuration():
    """Validate configuration file"""
    print("\n⚙️  Configuration Check:")
    
    try:
        with open('config.json', 'r') as f:
            config = json.load(f)
        
        # Check required sections
        required_sections = ['facebook', 'twilio', 'notifications', 'logging', 'scheduler', 'state']
        for section in required_sections:
            if section in config:
                print(f"   ✅ {section} section present")
            else:
                print(f"   ❌ {section} section missing")
                return False
        
        # Check Facebook groups
        if config['facebook']['groups']:
            print(f"   ✅ {len(config['facebook']['groups'])} Facebook groups configured")
        else:
            print("   ⚠️  No Facebook groups configured (add them later)")
        
        # Check intervals
        interval = config['facebook']['check_interval_minutes']
        if isinstance(interval, int) and interval > 0:
            print(f"   ✅ Check interval: {interval} minutes")
        else:
            print("   ❌ Invalid check interval")
            return False
        
        return True
        
    except FileNotFoundError:
        print("   ❌ config.json not found")
        return False
    except json.JSONDecodeError as e:
        print(f"   ❌ Invalid JSON in config.json: {e}")
        return False
    except Exception as e:
        print(f"   ❌ Error reading config.json: {e}")
        return False

def check_environment_template():
    """Check environment template"""
    print("\n🌍 Environment Template Check:")
    
    try:
        with open('.env.example', 'r') as f:
            content = f.read()
        
        required_vars = [
            'TWILIO_ACCOUNT_SID',
            'TWILIO_AUTH_TOKEN', 
            'TWILIO_PHONE_NUMBER',
            'YOUR_PHONE_NUMBER'
        ]
        
        all_present = True
        for var in required_vars:
            if var in content:
                print(f"   ✅ {var} template present")
            else:
                print(f"   ❌ {var} template missing")
                all_present = False
        
        return all_present
        
    except FileNotFoundError:
        print("   ❌ .env.example not found")
        return False
    except Exception as e:
        print(f"   ❌ Error reading .env.example: {e}")
        return False

def check_module_syntax():
    """Check Python module syntax"""
    print("\n🔍 Module Syntax Check:")
    
    modules = ['facebook_monitor.py', 'call_service.py', 'scheduler.py', 'setup.py']
    all_valid = True
    
    for module in modules:
        try:
            with open(module, 'r') as f:
                content = f.read()
            
            # Basic syntax check
            compile(content, module, 'exec')
            print(f"   ✅ {module} syntax valid")
            
        except SyntaxError as e:
            print(f"   ❌ {module} syntax error: {e}")
            all_valid = False
        except FileNotFoundError:
            print(f"   ❌ {module} not found")
            all_valid = False
        except Exception as e:
            print(f"   ❌ {module} error: {e}")
            all_valid = False
    
    return all_valid

def check_directories():
    """Check if required directories can be created"""
    print("\n📂 Directory Structure Check:")
    
    required_dirs = ['logs', 'data']
    all_ok = True
    
    for dirname in required_dirs:
        try:
            if not os.path.exists(dirname):
                os.makedirs(dirname, exist_ok=True)
                print(f"   ✅ {dirname}/ directory created")
            else:
                print(f"   ✅ {dirname}/ directory exists")
        except Exception as e:
            print(f"   ❌ Cannot create {dirname}/ directory: {e}")
            all_ok = False
    
    return all_ok

def check_permissions():
    """Check file permissions"""
    print("\n🔐 Permissions Check:")
    
    # Check if we can write to the current directory
    try:
        test_file = 'test_permissions.tmp'
        with open(test_file, 'w') as f:
            f.write('test')
        os.remove(test_file)
        print("   ✅ Write permissions available")
        return True
    except Exception as e:
        print(f"   ❌ Write permission error: {e}")
        return False

def generate_summary(checks):
    """Generate validation summary"""
    print("\n" + "=" * 50)
    print("VALIDATION SUMMARY")
    print("=" * 50)
    
    passed = sum(checks.values())
    total = len(checks)
    
    for check_name, result in checks.items():
        status = "✅ PASS" if result else "❌ FAIL"
        print(f"{check_name:<25}: {status}")
    
    print("-" * 50)
    print(f"Overall: {passed}/{total} checks passed")
    
    if passed == total:
        print("\n🎉 Installation validation PASSED!")
        print("Ready to run setup.py or configure manually.")
        return True
    else:
        print(f"\n⚠️  Installation validation FAILED!")
        print("Please fix the failing checks before proceeding.")
        return False

def main():
    """Run all validation checks"""
    print("=" * 50)
    print("Facebook Monitor - Installation Validator")
    print("=" * 50)
    
    checks = {
        'Python Version': check_python_version(),
        'Required Files': check_required_files(),
        'Configuration': check_configuration(),
        'Environment Template': check_environment_template(),
        'Module Syntax': check_module_syntax(),
        'Directories': check_directories(),
        'Permissions': check_permissions()
    }
    
    success = generate_summary(checks)
    return 0 if success else 1

if __name__ == "__main__":
    exit_code = main()
    sys.exit(exit_code)