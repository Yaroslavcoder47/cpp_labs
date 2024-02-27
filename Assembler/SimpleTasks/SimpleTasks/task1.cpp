#include "task1.h"

std::pair<int, int> task1(int num)
{
	uint8_t evenCounter = 0;
	uint8_t zeroCounter = 0;
	__asm{
		xor ch, ch
		xor cl, cl
		mov eax, num
		cmp eax, 0
		jl _abs
		jmp _loop
	_abs:
		neg eax
	_loop:
		cdq
		idiv eax, 10
		test edx, 1
		jnz _loop
		inc ch
		test edx
	}
}