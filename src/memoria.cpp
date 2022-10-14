#include "memoria.h"

HWND GetWindowHandleByName(LPCSTR name) {
    HWND wHandle = FindWindowA(0, name);
    return wHandle;
}

DWORD GetProcessIdFromWindowHandle(HWND wHandle) {
    DWORD pid;
    GetWindowThreadProcessId(wHandle, &pid); // get the process id using window handle
    return pid;
}

DWORD GetProcessIdByName(LPCSTR name) {
    return GetProcessIdFromWindowHandle(GetWindowHandleByName(name));
}

HANDLE GetProcessHandleByName(LPCSTR name, DWORD desired_access) {
    return OpenProcess(desired_access, FALSE, GetProcessIdByName(name));
}

int ReadInt(HANDLE pHandle, LPCVOID address) {
    int value;
    ReadProcessMemory(pHandle, address, &value, sizeof(int), 0);
    return value;
}