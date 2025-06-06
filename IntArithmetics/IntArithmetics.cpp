﻿#include <iostream>

/* 3. Найти все числа Фиббоначи для последовательности 0, 1, 1, 2, 3, 5, … ,  
которые могут быть вычислены в 32-разрядной арифметике (пока помещается результат). */
/* 4. Дробь задается целым числителем и натуральным знаменателем, сократить ее. */

int main() {
	const int n = 60;
	long int fib[n] = { 0 };
	__asm {
		mov fib[4], 1
		mov eax, 2
		BEG:
		cmp eax, n
			jge END

			mov ebx, fib[eax * 4 - 4]
			mov ecx, fib[eax * 4 - 8]
			add ebx, ecx
			jo END

			mov fib[eax * 4], ebx
			inc eax

			jmp BEG
			END :
		mov n, eax
	}
	std::cout << "Fibonacci Sequence: " << std::endl;
	for (int i = 0; i < n; i++) {
		std::cout << fib[i] << " ";
		if (i % 10 == 0 && i > 0)
			std::cout << std::endl;
	}
	return 0;
	
	/* ----------------------------------- */
	/* 
	int n, m;
	std::cout << "Enter numerator, denominator:" << std::endl;
	std::cin >> n >> m;
	bool isNegative;
	__asm {
		push n
		push m
		mov eax, n
		mov ebx, m

		cmp eax, 0
		jge GCD

		neg eax
		mov byte ptr [isNegative], 1
	GCD:
		cmp eax, ebx
		je DIVISION

		jl LESS
		sub eax, ebx
		jmp GCD
	LESS: 
		sub ebx, eax
		jmp GCD

	DIVISION:
		mov ecx, ebx
		xor edx, edx
		idiv ecx

		cmp byte ptr [isNegative], 0
		je END

		neg eax
	END:
		mov n, eax
		mov m, ebx
	}
	std::cout << "Result fraction: " << n << " / " << m << std::endl;
	*/
}
