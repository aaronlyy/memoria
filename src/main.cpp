/**
 * Usage example of memoria.h using the FPS Assault Cube
 * Last offset update: 17.10.2022
 */


#include <iostream>
#include <math.h>
#include "memoria.h"


int main() {

    uintptr_t off_health = 0xEC;
    uintptr_t off_x = 0x04;
    uintptr_t off_y = 0x08;
    uintptr_t off_z = 0x0C;
    uintptr_t off_yaw = 0x34;
    uintptr_t off_pitch = 0x38;
    uintptr_t off_current_height = 0x50;
    uintptr_t off_height = 0x054;
    uintptr_t off_direction = 0x80;
    uintptr_t off_shots = 0x188;

    // get base address
    char module_name[] = "client.dll"; // ac_client.exe also works?
    uintptr_t ac_client = GetModuleBaseAddress(_T(module_name), GetProcessIdByClass("SDL_app"));
    HANDLE pHandle = GetProcessHandleByClass("SDL_app", PROCESS_ALL_ACCESS);

    // add playerent offset to base and read value at address
    uintptr_t add_playerent = ac_client + 0x18AC00;
    uintptr_t playerent = ReadInt(pHandle, (LPCVOID)add_playerent);

    // calculate all addresses
    uintptr_t add_yaw = playerent + off_yaw;
    uintptr_t add_pitch = playerent + off_pitch;
    uintptr_t add_health = playerent + off_health;
    uintptr_t add_x = playerent + off_x;
    uintptr_t add_y = playerent + off_y;
    uintptr_t add_z = playerent + off_z;

    int health;
    float x, y, z;

    float saved_x = 0;
    float saved_y = 0;
    float saved_z = 0;

    std::cout << "### Memoria Example Code using Assault Cube ###\n";

    std::cout << "\n[General information]\n";

    std::cout << "[Base Address]: "<< std::hex << ac_client << "\n";
    std::cout << "[Player]: " << std::hex << playerent << "\n";

    std::cout << "\n[Hotkeys]\n";
    std::cout << "[NUMPAD0] -> Set HP to 100\n";
    std::cout << "[NUMPAD1] -> Save current position\n";
    std::cout << "[NUMPAD2] -> Aim at saved position\n";
    std::cout << "[NUMPAD9] -> Exit\n";

    while (true) {

        health = ReadInt(pHandle, (LPCVOID)add_health);
        x = ReadFloat(pHandle, (LPCVOID)add_x);
        y = ReadFloat(pHandle, (LPCVOID)add_y);
        z = ReadFloat(pHandle, (LPCVOID)add_z);

        if (GetAsyncKeyState(VK_NUMPAD0)) {
            WriteInt(pHandle, (LPVOID)add_health, 100);
        }

        if (GetAsyncKeyState(VK_NUMPAD9)) {
            break;
        }

        if (GetAsyncKeyState(VK_NUMPAD1)) {
            saved_x = x;
            saved_y = y;
            saved_z = z;
        }

        if (GetAsyncKeyState(VK_NUMPAD2)) {
            double new_pitch = calculatePitchToPosition(x, y, z, saved_x, saved_y, saved_z);
            double new_yaw = calculateYawToPosition(x, y, saved_x, saved_y);
            WriteFloat(pHandle, (LPVOID)add_pitch, (float)new_pitch);
            WriteFloat(pHandle, (LPVOID)add_yaw, (float)new_yaw );
        }

        if (health < 50) {
            WriteInt(pHandle, (LPVOID)add_health, 100);
        }
    }
}