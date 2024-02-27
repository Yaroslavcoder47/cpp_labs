#include "task1.h"

//std::pair<int, int> task1(int num)
void task1(int num)
{
	uint8_t evenCounter = 0;
	uint8_t zeroCounter = 0;
	__asm{
		mov bh, 10
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
		idiv bh
		test edx, 1
		jnz _loop
		inc ch
		test edx, 0xFFFF
		jz _incr
		jmp _loop
		_incr:
			inc cl
			//jmp _loop
		mov evenCounter, ch
		mov zeroCounter, cl
	}

	std::cout << static_cast<int>(evenCounter) << '\n';
	std::cout << static_cast<int>(zeroCounter) << '\n';
}