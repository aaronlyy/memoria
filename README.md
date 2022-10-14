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
  - DWORD GetProcessIdFromWindowHandle(HWND wHandle);
  - DWORD GetProcessIdByClass(LPCSTR class_name);
  - DWORD GetProcessIdByTitle(LPCSTR window_title);
- PROCESS HANDLE
  - HANDLE GetProcessHandleByClass(LPCSTR class_name, DWORD desired_access);
  - HANDLE GetProcessHandleByTitle(LPCSTR window_title, DWORD desired_access);
- READ
  - int ReadInt(HANDLE pHandle, LPCVOID address);

## Example

Simple example using the first-person shooter Assault Cube.

```c++
#include <iostream> // cout
#include <unistd.h> // sleep
#include "memoria.h"

int main() {
    HANDLE pHandle = GetProcessHandleByName("AssaultCube", PROCESS_ALL_ACCESS); // Get handle to AssaultCube

    int health;

    while (true) {
        health = ReadInt(pHandle, (LPCVOID)0x0070ADEC); // Read value from address

        if (health > 0) {
            std::cout << "Current health: " << health << "\n";
        }
        else {
            std::cout << "Dead?\n";
        }
        sleep(1);
    }
}

```

## ToDo

- GetWindowHandleByClass
- GetProcessHandleByClass
- GetProcessIdByClass
- GetModuleBaseAddressByName
- GetModuleByName

## About

Made with ♥ by [aaronlyy](https://github.com/aaronlyy)