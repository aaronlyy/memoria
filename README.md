<p align="center"><img src="./media/brain.png"/></p>
<h1 align=center> Memoria: Read and Write Process Memory on Windows</h1>

## Info
Memoria offers various functions and methods that will make your life easier while working with process memory on windows.

This Project is work in progress and in a very early stage of development.

## Available functions

- HWND GetWindowHandleByName(LPCSTR name);
- DWORD GetProcessIdFromWindowHandle(HWND wHandle);
- DWORD GetProcessIdByName(LPCSTR name);
- HANDLE GetProcessHandleByName(LPCSTR name, DWORD desired_access);
- int ReadInt(HANDLE pHandle, LPCVOID address);

## ToDo

- GetModuleBaseAddressByName
- GetModuleByName

## About

Made with ♥ by [aaronlyy](https://github.com/aaronlyy)