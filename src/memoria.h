//
// Created by aaronlyy on 14.10.2022.
//

#ifndef MEMORIA_MEMORIA_H
#define MEMORIA_MEMORIA_H

#include <windows.h>

HWND GetWindowHandleByName(LPCSTR name);
DWORD GetProcessIdFromWindowHandle(HWND wHandle);
DWORD GetProcessIdByName(LPCSTR name);
HANDLE GetProcessHandleByName(LPCSTR name, DWORD desired_access);
int ReadInt(HANDLE pHandle, LPCVOID address);

#endif //MEMORIA_MEMORIA_H