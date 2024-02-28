#include "task1.h"

//std::pair<int, int> task1(int num)
void task1(int num)
{
	uint8_t evenCounter = 0;
	uint8_t zeroCounter = 0;
	__asm {
		mov bl, 0x0A
		xor ch, ch
		xor cl, cl
		mov eax, num
		mov edx, 0
		cmp eax, 0
		jl _abs
		jmp _loop
		_abs :
			neg eax
		_loop :
			cdq
			idiv bl
			test eax, 1
			jnz _check
			inc ch
			test eax, eax
			jnz _check
			inc cl
			jmp _check
		_check:
			test edx, edx
			jnz _loop
			jmp _end
		_end:
			mov evenCounter, ch
			mov zeroCounter, cl
	}

	std::cout << static_cast<int>(evenCounter) << '\n';
	std::cout << static_cast<int>(zeroCounter) << '\n';
}