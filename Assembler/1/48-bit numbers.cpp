#include <iostream>
#include <string>
#include <cstdint>
#include <iomanip>
#include <bitset>

int main() {
    uint16_t A1, A2, B1, B2, C1, C2;
    int16_t A3, B3, C3;

    std::cout << "Enter 16-bit numbers A1, A2, A3:" << std::endl;
    std::cin >> A1 >> A2 >> A3;
    std::cout << "Enter 16-bit numbers B1, B2, B3:" << std::endl;
    std::cin >> B1 >> B2 >> B3;

    _asm {
        mov ax, A1
        add ax, B1
        mov C1, ax

        jnc no_first_carry
        mov ax, A2
        inc ax
        mov A2, ax

        jnc no_first_carry
        mov ax, A3
        inc ax
        mov A3, ax

     no_first_carry:
        mov ax, A2
        add ax, B2
        mov C2, ax

        jnc no_second_carry
        mov ax, A3
        inc ax
        mov A3, ax

    no_second_carry:
        mov ax, A3
        add ax, B3
        mov C3, ax
    }
    std::cout << "Result (HEX): ";
    std::cout << std::hex << std::setfill('0') << std::setw(4) << C1 << ' ';
    std::cout << std::setfill('0') << std::setw(4) << C2 << ' ';
    std::cout << std::setfill('0') << std::setw(4) << C3 << std::endl;
    std::cout << "Result (DEC): ";
    std::cout << std::dec << C1 << ' ' << C2 << ' ' << C3;

}