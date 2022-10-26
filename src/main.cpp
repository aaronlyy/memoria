/**
 * Usage example of memoria.h using the FPS Assault Cube
 * Last offset update: 17.10.2022
 */

#include <iostream>
#include <cmath>
#include "offsets.h"
#include "memoria.h"

using namespace memoria;

int main() {
    HANDLE pHandle = nullptr;
    while (pHandle == nullptr) {
        pHandle = GetProcessHandleByClass("SDL_app", PROCESS_ALL_ACCESS);
    }

    // get base address
    char module_name[] = "client.dll"; // ac_client.exe also works?
    uintptr_t ac_client = GetModuleBaseAddress(_T(module_name), GetProcessIdByClass("SDL_app"));

    // add playerent offset to base and read value at address
    uintptr_t add_playerent = ac_client + 0x18AC00;
    uintptr_t playerent = ReadInt(pHandle, add_playerent);

    // calculate all addresses
    uintptr_t add_yaw = playerent + offsets::yaw;
    uintptr_t add_pitch = playerent + offsets::pitch;
    uintptr_t add_health = playerent + offsets::health;
    uintptr_t add_x = playerent + offsets::x;
    uintptr_t add_y = playerent + offsets::y;
    uintptr_t add_z = playerent + offsets::z;

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

        health = ReadInt(pHandle, add_health);
        x = ReadFloat(pHandle, add_x);
        y = ReadFloat(pHandle, add_y);
        z = ReadFloat(pHandle, add_z);

        if (GetAsyncKeyState(VK_NUMPAD0)) {
            WriteInt(pHandle, add_health, 100);
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
            double new_pitch = CalculatePitchToPosition(x, y, z, saved_x, saved_y, saved_z);
            double new_yaw = CalculateYawToPosition(x, y, saved_x, saved_y);
            WriteFloat(pHandle, add_pitch, (float)new_pitch);
            WriteFloat(pHandle, add_yaw, (float)new_yaw);
        }

        if (health < 50) {
            WriteInt(pHandle, add_health, 100);
        }
    }
}

/*
 * Find the entity list
 * 1. Start Bot TDM with "idlebots 1"
 * 2. Search for 100 int
 * 3. Shoot at enemy
 * 4. Search for decreased value
 * 5. Repeat 3 & 4 until enemy health adress found
 * 6. Pointerscan this address (set ending Offset to EC)
 * 7. Restart Assault Cube
 * 8. Search for value 100 in Pointerscan
 * 9. Move Pointers down with the least amount of offsets
 * 10. Dissect Data/Structures for these pointers
 * 11. Done.
 * */