#ifndef MEMORIA_MEMORIA_H
#define MEMORIA_MEMORIA_H

#include <windows.h>
#include <TlHelp32.h>
#include <tchar.h>
#include <cstdint>
#include <unistd.h>

// --- WINDOW HANDLE ---
/**
 * Get a Window handle using the window title.
 *
 * @param window_title Title of a window
 * @return HWND window_handle
 */
HWND GetWindowHandleByTitle(LPCSTR window_title);

/**
 * Get a Window handle using the class name.
 *
 * @param class_name Name of a class
 * @return HWND window_handle
 */
HWND GetWindowHandleByClass(LPCSTR class_name);

// --- PROCESS ID ---
DWORD GetProcessIdFromWindowHandle(HWND window_handle);
DWORD GetProcessIdByTitle(LPCSTR window_title);
DWORD GetProcessIdByClass(LPCSTR class_name);

// --- PROCESS HANDLE ---
HANDLE GetProcessHandleByProcessId(DWORD process_id, DWORD desired_access);
HANDLE GetProcessHandleByTitle(LPCSTR window_title, DWORD desired_access);
HANDLE GetProcessHandleByClass(LPCSTR class_name, DWORD desired_access);

// BASE ADDRESS
uintptr_t GetModuleBaseAddress(TCHAR* modName, DWORD procId);

// --- READ ---
int ReadInt(HANDLE pHandle, LPCVOID address);
double ReadDouble(HANDLE pHandle, LPCVOID address);
float ReadFloat(HANDLE pHandle, LPCVOID address);

// --- WRITE ---
void WriteInt(HANDLE pHandle, LPVOID address, int value);
void WriteDouble(HANDLE pHandle, LPVOID address, double value);
void WriteFloat(HANDLE pHandle, LPVOID address, float value);

#endif //MEMORIA_MEMORIA_H