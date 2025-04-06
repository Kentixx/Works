#include <iostream>
#include <cmath>

/* 3. (4 * x – 1) * (4 * x + 1) / 4 */
/* 7. Для двух натуральных чисел n, m получить сумму m последних цифр числа n. */

int main()
{
    int x, result;
    std::cout << "x = ";
    std::cin >> x;
    int a = (4 * x - 1) * (4 * x + 1) / 4;
    __asm {
        mov ecx, 4
        mov eax, x
        imul ecx
        mov ebx, eax

        dec ebx
        inc eax
        imul ebx
        idiv ecx
        
        mov result, eax
    }
    std::cout << a << std::endl;
    std::cout << "Result: " << result << std::endl;

    /* ----------------------- */

    int n, m, result_sum = 0;
    std::cout << "n = ";
    std::cin >> n;
    std::cout << "m = ";
    std::cin >> m;
    /*
    * int d;
    * for (int i = 0; i < m; ++i) {
    *     d = (n % (int)pow(10, i + 1)) / pow(10, i);
    *     result_sum += d;
    * }
    */
    __asm {
        mov ecx, m
        mov ebx, 1
    parse:
        push ebx
        imul ebx, 10
        xor edx, edx
        mov eax, n
        idiv ebx       ; n % 10^(i+1)

        pop ebx        ; ebx = 10^i 
        mov eax, edx
        xor edx, edx
        div ebx
        add result_sum, eax
        imul ebx, 10

        loop parse
    }
    std::cout << "Result sum: " << result_sum << std::endl;
}
