#ifndef MEMORIA_MEMORIA_H
#define MEMORIA_MEMORIA_H

#include <windows.h>
#include <TlHelp32.h>
#include <tchar.h>
#include <cstdint>
#include <cmath>

namespace memoria {

// --- WINDOW HANDLE ---
/**
 * Get a Window handle using the window title.
 *
 * @param LPCSTR window_title
 * @return HWND window_handle
 */
    HWND GetWindowHandleByTitle(LPCSTR window_title);

/**
 * Get a Window handle using the class name.
 *
 * @param LPCSTR class_name
 * @return HWND window_handle
 */
    HWND GetWindowHandleByClass(LPCSTR class_name);

// --- PROCESS ID ---
/**
 * Get the process ID of a process by its window handle
 *
 * @param HWND window_handle
 * @return DWORD process_id
 */
    DWORD GetProcessIdFromWindowHandle(HWND window_handle);

/**
 * Get the process ID of a process by its window title
 *
 * @param LPCSTR window_title
 * @return DWORD process_id
 */
    DWORD GetProcessIdByTitle(LPCSTR window_title);

/**
 * Get the process ID of a process by its class name
 *
 * @param LPCSTR class name
 * @return DWORD process_id
 */
    DWORD GetProcessIdByClass(LPCSTR class_name);

// --- PROCESS HANDLE ---
/**
 * Get the process handle of a process by its process id
 *
 * @param DWORD process_id
 * @param DWORD desired_access
 * @return HANDLE process_handle
 */
    HANDLE GetProcessHandleByProcessId(DWORD process_id, DWORD desired_access);

/**
 * Get the process handle of a process by its window_title
 *
 * @param LPCSTR window_title
 * @param DWORD desired_access
 * @return HANDLE process_handle
 */
    HANDLE GetProcessHandleByTitle(LPCSTR window_title, DWORD desired_access);

/**
 * Get the process handle of a process by its class name
 *
 * @param LPCSTR class_name
 * @param DWORD desired_access
 * @return HANDLE process_handle
 */
    HANDLE GetProcessHandleByClass(LPCSTR class_name, DWORD desired_access);

// BASE ADDRESS
/**
 * Get the base adress of a specific module
 *
 * @param TCHAR* modName
 * @param DWORD procId
 * @return uintptr_t base_address
 */
    uintptr_t GetModuleBaseAddress(TCHAR *modName, DWORD procId);

// --- READ ---
    int ReadInt(HANDLE pHandle, uintptr_t address);

    double ReadDouble(HANDLE pHandle, uintptr_t address);

    float ReadFloat(HANDLE pHandle, uintptr_t address);

// --- WRITE ---
    void WriteInt(HANDLE pHandle, uintptr_t address, int value);

    void WriteDouble(HANDLE pHandle, uintptr_t address, double value);

    void WriteFloat(HANDLE pHandle, uintptr_t address, float value);

// --- MATH ---
/**
 * Calculate the distance between to points in a three dimensional space
 *
 * @param double x1
 * @param double y1
 * @param double x2
 * @param double y2
 * @return double distance
 */
    double CalculateDistance(double x1, double y1, double x2, double y2);

    double CalculateYawToPosition(double x1, double y1, double x2, double y2);

    double CalculatePitchToPosition(double x1, double y1, double z1, double x2, double y2, double z2);

// --- UTIL ---
/**
 * Cast an uintptr_t to an LPCVOID
 *
 * @param uintptr_t address
 * @return LPCVOID pointer
 */
    LPCVOID AddressToPointerC(uintptr_t address);

/**
 * Cast an uintptr_t to an LPVOID
 *
 * @param uintptr_t address
 * @return LPVOID pointer
 */
    LPVOID AddressToPointer(uintptr_t address);

}

#endif //MEMORIA_MEMORIA_H