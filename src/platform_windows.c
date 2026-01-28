#include "platform.h"
#include <windows.h>
#include <stdio.h>

void ensure_config_dir(void)
{
    char appdata[MAX_PATH];
    GetEnvironmentVariableA("APPDATA", appdata, MAX_PATH);

    char dir[MAX_PATH];
    snprintf(dir, MAX_PATH, "%s\\wstaion", appdata);

    CreateDirectoryA(dir, NULL);
}

void get_path_file(char *buffer, size_t size)
{
    char appdata[MAX_PATH];
    GetEnvironmentVariableA("APPDATA", appdata, MAX_PATH);

    snprintf(buffer, size, "%s\\wstaion\\path.txt", appdata);
}

void run_command(const char *cmd)
{
    STARTUPINFOA si = {0};
    PROCESS_INFORMATION pi = {0};
    si.cb = sizeof(si);

    char command[1024];
    snprintf(command, sizeof(command), "cmd.exe /C %s", cmd);

    CreateProcessA(
        NULL,
        command,
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &si,
        &pi
    );

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
}

void sleep_ms(int ms)
{
    Sleep(ms);
}
