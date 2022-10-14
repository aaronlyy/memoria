# memoria: Read and Write process memory on Windows

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