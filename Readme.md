## Description



Silent Windows registry hive stealer - When run as Administrator, this tool automatically saves the SYSTEM, SECURITY, and SAM registry hives and transfers them to a hardcoded network share. Perfect for authorized penetration testing where you need quick credential extraction from compromised systems.



## Usage



Usage:

```

hive_stealer.exe

```



* No command-line arguments



* No configuration files



* Just run as Administrator

### Note:
  - Quick setup: Run python smbserver.py -smb2support CompData . on your attack machine first, then execute the tool on the target Windows system with Admin rights.
