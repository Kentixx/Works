#include <iostream>

/* 3. Найти все числа Фиббоначи для последовательности 0, 1, 1, 2, 3, 5, … ,  
которые могут быть вычислены в 32-разрядной арифметике (пока помещается результат). */
/* 4. Дробь задается целым числителем и натуральным знаменателем, сократить ее. */

int main() {
	const int n = 50;
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
	std::cout << "\n\n";

	/* ----------------------------------- */
	
	int num, den;
	do {
		std::cout << "Enter numerator, denominator:" << std::endl;
		std::cin >> num >> den;
		if (den <= 0) {
			std::cout << "Denominator can't be less or equal 0!" << std::endl;
		}
	} while (den <= 0);
	__asm {
		mov eax, num
		mov ebx, den

		cmp eax, 0
		jg GCD
		je _END

		neg eax
	GCD:
		cmp eax, ebx
		je DIVISION
		jg GREATER
		jl LESS

	GREATER:
		sub eax, ebx
		jmp GCD

	LESS: 
		sub ebx, eax
		jmp GCD

	DIVISION:
		mov ecx, eax
		mov eax, num
		cdq
		idiv ecx
		mov num, eax

		mov eax, den
		cdq
		idiv ecx
		mov den, eax

	_END:
	}
	if (den == 1) {
		std::cout << "Result fraction: " << num << std::endl;
	} else {
		std::cout << "Result fraction: " << num << " / " << den << std::endl;
	}
	return 0;
}