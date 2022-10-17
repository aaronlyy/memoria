<p align="center"><img src="./media/brain.png"/></p>
<h1 align=center> Memoria: Read and Write Process Memory on Windows</h1>

## Info
Memoria offers various functions and methods that will make your life easier while working with process memory on windows.

This Project is work in progress and in a very early stage of development.

## Available functions

- WINDOW HANDLE
  - HWND GetWindowHandleByClass(LPCSTR class_name);
  - HWND GetWindowHandleByTitle(LPCSTR window_title);
- PROCESS ID
  - DWORD GetProcessIdFromWindowHandle(HWND window_handle);
  - DWORD GetProcessIdByClass(LPCSTR class_name);
  - DWORD GetProcessIdByTitle(LPCSTR window_title);
- PROCESS HANDLE
  - HANDLE GetProcessHandleByClass(LPCSTR class_name, DWORD desired_access);
  - HANDLE GetProcessHandleByTitle(LPCSTR window_title, DWORD desired_access);
- BASE ADRESS
  - uintptr_t GetModuleBaseAddress(TCHAR* modName, DWORD procId);
- READ
  - int ReadInt(HANDLE pHandle, LPCVOID address);
  - double ReadDouble(HANDLE pHandle, LPCVOID address);
  - float ReadFloat(HANDLE pHandle, LPCVOID address);
- WRITE
  - void WriteInt(HANDLE pHandle, LPVOID address, int value);
  - void WriteDouble(HANDLE pHandle, LPVOID address, double value);
  - void WriteFloat(HANDLE pHandle, LPVOID address, float value);

## ToDo

- GetModuleBaseAddressByProcessId
- GetModuleBaseAddressByName
- GetModuleBaseAddressByClass

## About

Made with ♥ by [aaronlyy](https://github.com/aaronlyy)