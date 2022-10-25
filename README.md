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
  - int ReadInt(HANDLE pHandle, uintptr_t address);
  - double ReadDouble(HANDLE pHandle, uintptr_t address);
  - float ReadFloat(HANDLE pHandle, uintptr_t address);
- WRITE
  - void WriteInt(HANDLE pHandle, uintptr_t address, int value);
  - void WriteDouble(HANDLE pHandle, uintptr_t address, double value);
  - void WriteFloat(HANDLE pHandle, uintptr_t address, float value);
- MATH
  - double CalculateDistance(double x1, double y1, double x2, double y2);
  - double CalculateYawToPosition(double x1, double y1, double x2, double y2);
  - double CalculatePitchToPosition(double x1, double y1, double z1, double x2, double y2, double z2);
- UTIL
  - LPCVOID AddressToPointerC(uintptr_t address);
  - LPVOID AddressToPointer(uintptr_t address);
## Showcase

[![yaw & pitch calculation test](https://img.youtube.com/vi/YhmHOjOGIBI/0.jpg)](https://www.youtube.com/watch?v=YhmHOjOGIBI)

## ToDo

- GetModuleBaseAddressByProcessId
- GetModuleBaseAddressByName
- GetModuleBaseAddressByClass
- Overload functions to take std::string
- Overload Read and Write functions to take a reference

## About

Made with ♥ by [aaronlyy](https://github.com/aaronlyy)