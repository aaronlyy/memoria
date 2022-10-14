#include <iostream>
#include "memoria.h"

int main() {

    uintptr_t off_health = 0xEC;
    uintptr_t off_x = 0x04;
    uintptr_t off_y = 0x0C;
    uintptr_t off_z = 0x08;
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
    std::cout << "Base Address: "<< std::hex << ac_client << "\n";

    // add playerent offset to base and read value at address
    uintptr_t add_playerent = ac_client + 0x18AC00;
    std::cout << "Base + Playerent Offset: " << std::hex << add_playerent << "\n";
    uintptr_t playerent = ReadInt(pHandle, (LPCVOID)add_playerent);
    std::cout << "Playerent: " << std::hex << playerent << "\n";

    // calculate all addresses
    uintptr_t add_yaw = playerent + off_yaw;
    uintptr_t add_pitch = playerent + off_pitch;
    uintptr_t add_health = playerent + off_health;

    int health, direction, shots;
    double x, y, z, height, curr_height, yaw, pitch;

    // main loop
    while (true) {
        health = ReadInt(pHandle, (LPCVOID)add_health);
        yaw = ReadFloat(pHandle, (LPCVOID)add_yaw);
        pitch = ReadFloat(pHandle, (LPCVOID)add_pitch);

        std::cout << "Health: " << std::dec << health << "\n";
        // std::cout << "X: " << std::dec << health << "\n";
        // std::cout << "Y: " << std::dec << health << "\n";
        // std::cout << "Z: " << std::dec << health << "\n";
        // std::cout << "Height: " << std::dec << health << "\n";
        // std::cout << "Current Height: " << std::dec << health << "\n";
        // std::cout << "Direction: " << std::dec << health << "\n";
        // std::cout << "Shots fired: " << std::dec << health << "\n";
        std::cout << "Yaw: " << std::dec << yaw << "\n";
        std::cout << "Pitch: " << std::dec << pitch << "\n";
        sleep(1);
    }
}