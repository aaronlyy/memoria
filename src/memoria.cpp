#include "memoria.h"


// --- WINDOW HANDLE ---
HWND GetWindowHandleByTitle(LPCSTR window_title) {
    HWND wHandle = FindWindowA(nullptr, window_title);
    return wHandle;
}

HWND GetWindowHandleByClass(LPCSTR class_name) {
    HWND wHandle = FindWindowA(class_name, nullptr);
    return wHandle;
}

// --- PROCESS ID ---
DWORD GetProcessIdFromWindowHandle(HWND wHandle) {
    DWORD pid;
    GetWindowThreadProcessId(wHandle, &pid); // get the process id using window handle
    return pid;
}

DWORD GetProcessIdByTitle(LPCSTR window_title) {
    return GetProcessIdFromWindowHandle(GetWindowHandleByTitle(window_title));
}

DWORD GetProcessIdByClass(LPCSTR class_name) {
    return GetProcessIdFromWindowHandle(GetWindowHandleByClass(class_name));
}


// --- PROCESS HANDLE ---
HANDLE GetProcessHandleByTitle(LPCSTR window_title, DWORD desired_access) {
    return OpenProcess(desired_access, FALSE, GetProcessIdByTitle(window_title));
}

HANDLE GetProcessHandleByClass(LPCSTR class_name, DWORD desired_access) {
    return OpenProcess(desired_access, FALSE, GetProcessIdByClass(class_name));
}

// --- READ ---
int ReadInt(HANDLE pHandle, LPCVOID address) {
    int value;
    ReadProcessMemory(pHandle, address, &value, sizeof(int), 0);
    return value;
}

// --- WRITE ---