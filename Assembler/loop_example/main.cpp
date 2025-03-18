#include <iostream>

int main(){
    int a = 5;

    __asm {
        lp_j:
            inc a
            cmp a, 10
            jne lp_j

            mov ecx, 11
        lp_l:
            inc a
            cmp a, 15
            je end
            loop lp_l
        end:
    }
    
    std::cout << a << std::endl;
}