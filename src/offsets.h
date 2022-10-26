#ifndef MEMORIA_OFFSETS_H
#define MEMORIA_OFFSETS_H

#include <cstdint>

namespace offsets {
    constexpr uintptr_t health = 0xEC;
    constexpr uintptr_t x = 0x04;
    constexpr uintptr_t y = 0x08;
    constexpr uintptr_t z = 0x0C;
    constexpr uintptr_t yaw = 0x34;
    constexpr uintptr_t pitch = 0x38;
    constexpr uintptr_t current_height = 0x50;
    constexpr uintptr_t height = 0x054;
    constexpr uintptr_t direction = 0x80;
    constexpr uintptr_t shots = 0x188;
}

#endif //MEMORIA_OFFSETS_H
