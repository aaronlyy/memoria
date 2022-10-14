#include <iostream>
#include "memoria.h"

int main() {

    // get base address
    char module_name[] = "ac_client.exe"; // ac_client.exe also works?
    uintptr_t ac_client = GetModuleBaseAddress(_T(module_name), GetProcessIdByClass("SDL_app"));
    HANDLE pHandle = GetProcessHandleByClass("SDL_app", PROCESS_ALL_ACCESS);
    std::cout << "Base Address: "<< std::hex << ac_client << "\n";

    // add playerent offset to base and read value at address
    uintptr_t add_playerent = ac_client + 0x17E254;
    std::cout << "Base + Playerent Offset: " << std::hex << add_playerent << "\n";
    uintptr_t playerent = ReadInt(pHandle, (LPCVOID)add_playerent);
    std::cout << "Playerent: " << std::hex << playerent << "\n";

    // add health offset to playernt and get value
    uintptr_t add_health = playerent + 0xEC;
    std::cout << "Health address: " << std::hex << add_health << "\n";
    int health;

    while (true) {
        health = ReadInt(pHandle, (LPCVOID)0x8e403c);
        std::cout << "Current health: " << std::dec << health << "\n";
        sleep(1);
    }
}