//
// Created by aaronlyy on 14.10.2022.
//

#ifndef MEMORIA_MEMORIA_H
#define MEMORIA_MEMORIA_H

#include <windows.h>

// --- WINDOW HANDLE ---
HWND GetWindowHandleByTitle(LPCSTR window_title);
HWND GetWindowHandleByClass(LPCSTR class_name);

// --- PROCESS ID ---
DWORD GetProcessIdFromWindowHandle(HWND wHandle);
DWORD GetProcessIdByTitle(LPCSTR window_title);
DWORD GetProcessIdByClass(LPCSTR class_name);

// --- PROCESS HANDLE ---
HANDLE GetProcessHandleByTitle(LPCSTR window_title, DWORD desired_access);
HANDLE GetProcessHandleByClass(LPCSTR class_name, DWORD desired_access);

// --- READ ---
int ReadInt(HANDLE pHandle, LPCVOID address);

// --- WRITE ---

#endif //MEMORIA_MEMORIA_H