#include <iostream>
#include "memoria.h"
#include <unistd.h>

int main() {
    HANDLE pHandle = GetProcessHandleByName("AssaultCube", PROCESS_ALL_ACCESS);

    int health;

    while (true) {
        health = ReadInt(pHandle, (LPCVOID)0x0070ADEC);

        if (health > 0) {
            std::cout << "Current health: " << health << "\n";
        }
        else {
            std::cout << "Dead?\n";
        }
        sleep(1); // test
    }
}