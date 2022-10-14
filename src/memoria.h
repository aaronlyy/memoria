//
// Created by aaronlyy on 14.10.2022.
//

#ifndef MEMORIA_MEMORIA_H
#define MEMORIA_MEMORIA_H

#include <windows.h>
#include<TlHelp32.h>
#include <tchar.h>
#include <cstdint>
#include <unistd.h>

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

// BASE ADDRESS
uintptr_t GetModuleBaseAddress(TCHAR* modName, DWORD procId);

// --- READ ---
int ReadInt(HANDLE pHandle, LPCVOID address);

// --- WRITE ---
void WriteInt(HANDLE pHandle, LPVOID address, int value);

#endif //MEMORIA_MEMORIA_H