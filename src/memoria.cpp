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

// BASE ADDRESS
uintptr_t GetModuleBaseAddress(TCHAR* modName, DWORD processId) {

    uintptr_t base_address = 0;

    // takes snapshot of all loaded modules in process
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, processId);

    // check if snapshot is valid
    if (hSnap != INVALID_HANDLE_VALUE) {

        // create struct that holds the module info while iterating
        MODULEENTRY32 moduleEntry;
        moduleEntry.dwSize = sizeof(moduleEntry);

        // if a module exists in snapshot, get entry
        if (Module32First(hSnap, &moduleEntry)) { // select first entry
            do {
                if (_tcscmp(moduleEntry.szModule, modName)) { // check if current module name equals searched module
                    base_address = (uintptr_t) moduleEntry.modBaseAddr;
                    break;
                }
            }
            while (Module32Next(hSnap, &moduleEntry)); // select next module
        }
    }

    CloseHandle(hSnap);
    return base_address;
}

// --- READ ---
int ReadInt(HANDLE pHandle, LPCVOID address) {
    int buffer;
    ReadProcessMemory(pHandle, address, &buffer, sizeof(int), nullptr);
    return buffer;
}

// --- WRITE ---
void WriteInt(HANDLE pHandle, LPVOID address, int value) {
    WriteProcessMemory(pHandle, address, &value, sizeof(int), nullptr);
}