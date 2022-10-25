#include "memoria.h"

// --- WINDOW HANDLE ---
HWND GetWindowHandleByTitle(LPCSTR window_title) {
    HWND window_handle = FindWindowA(nullptr, window_title);
    return window_handle;
}

HWND GetWindowHandleByClass(LPCSTR class_name) {
    HWND window_handle = FindWindowA(class_name, nullptr);
    return window_handle;
}

// --- PROCESS ID ---
DWORD GetProcessIdFromWindowHandle(HWND window_handle) {
    DWORD process_id;
    GetWindowThreadProcessId(window_handle, &process_id); // get the process id using window handle
    return process_id;
}

DWORD GetProcessIdByTitle(LPCSTR window_title) {
    return GetProcessIdFromWindowHandle(GetWindowHandleByTitle(window_title));
}

DWORD GetProcessIdByClass(LPCSTR class_name) {
    return GetProcessIdFromWindowHandle(GetWindowHandleByClass(class_name));
}

// --- PROCESS HANDLE ---

HANDLE GetProcessHandleByProcessId(DWORD process_id, DWORD desired_access) {
    return OpenProcess(desired_access, FALSE, process_id);
}

HANDLE GetProcessHandleByTitle(LPCSTR window_title, DWORD desired_access) {
    return GetProcessHandleByProcessId(GetProcessIdByTitle(window_title), desired_access);
}

HANDLE GetProcessHandleByClass(LPCSTR class_name, DWORD desired_access) {
    return GetProcessHandleByProcessId(GetProcessIdByClass(class_name), desired_access);
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

int ReadInt(HANDLE pHandle, uintptr_t address) {
    int buffer;
    ReadProcessMemory(pHandle, (LPCVOID)address, &buffer, sizeof(int), nullptr);
    return buffer;
}

double ReadDouble(HANDLE pHandle, uintptr_t address) {
    double buffer;
    ReadProcessMemory(pHandle, (LPCVOID)address, &buffer, sizeof(double), nullptr);
    return buffer;
}

float ReadFloat(HANDLE pHandle, uintptr_t address) {
    float buffer;
    ReadProcessMemory(pHandle, (LPCVOID)address, &buffer, sizeof(float), nullptr);
    return buffer;
}

// --- WRITE ---
void WriteInt(HANDLE pHandle, uintptr_t address, int value) {
    WriteProcessMemory(pHandle, (LPVOID)address, &value, sizeof(int), nullptr);
}

void WriteDouble(HANDLE pHandle, uintptr_t address, double value) {
    WriteProcessMemory(pHandle, (LPVOID)address, &value, sizeof(double), nullptr);
}

void WriteFloat(HANDLE pHandle, uintptr_t address, float value) {
    WriteProcessMemory(pHandle, (LPVOID)address, &value, sizeof(float), nullptr);
}

// --- MATH ---
double CalculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

double CalculateYawToPosition(double x1, double y1, double x2, double y2) {
    return atan2(y2 - y1, x2 - x1) * 180 / M_PI + 90;
}

double CalculatePitchToPosition(double x1, double y1, double z1, double x2, double y2, double z2) {
    return atan2(z2 - z1, CalculateDistance(x1, y1, x2, y2)) * 180 / M_PI;
}

// --- UTIL ---
LPCVOID AddressToPointerC(uintptr_t address) {
    return (LPCVOID)address;
}

LPVOID AddressToPointer(uintptr_t address) {
    return (LPVOID)address;
}