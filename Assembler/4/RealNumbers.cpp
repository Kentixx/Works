#include <iostream>
#include <iomanip>

int main() {
	double PI;
	const int TWO = 2, EIGHT = 8, TEN = 10;
	int precision = 0, newPrecision = 1;
	int k = 0;
	double sum = 0;
	int intPI, intSum;
	int controlWord, newControlWord;
	std::cout << "Dec Precision | Iterations | PI | Calc result" << std::endl;
	for (int i = 1; i <= 200000; ++i) {
		__asm {
			FINIT
			mov ecx, i
		CYCLE1:
			mov k, ecx
			FILD TWO
			FILD dword ptr [k]
			FMUL
			FLD1
			FSUB   ; (2k - 1) 
			FMUL ST(0), ST(0)  ; (2k - 1)^2
			FLD1
			FDIVR  ; 1/(2k - 1)^2
			FADD sum
			FSTP sum

			loop CYCLE1

			FILD EIGHT
			FMUL sum
			FSQRT 
			FST sum 

			FLDPI 
			FST PI


			mov ecx, newPrecision
			FILD TEN
		CYCLE2:
			FMUL ST(1), ST
			FMUL ST(2), ST

			loop CYCLE2
			FSTP ST(0)

			FNSTCW controlWord  ; сохранение состояния регистра управления в controlWord

			mov eax, 0F3Fh
			mov newControlWord, eax
			FLDCW newControlWord

			FISTP intPI
			FISTP intSum
			FLDCW controlWord

			mov eax, intPI
			cmp eax, intSum
			jne END
			inc precision

		END:
		}
		if (i % 5000 == 0) {
			std::cout << std::setprecision(15) << newPrecision << "\t";
			std::cout << i << "\t";
			std::cout << PI << "\t";
			std::cout << sum << '\n';
			++newPrecision;
		}
		sum = 0;
		k = 0;
	}
}