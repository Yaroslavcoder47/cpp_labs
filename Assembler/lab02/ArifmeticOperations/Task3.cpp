#include "Task3.h"

int task3(unsigned int a)
{
	int n = 1;
	__asm {
		mov ecx, 1
		mov eax, a
		jo end_
		begin_ :
		imul a
			jo end_
			add ecx, 1
			jmp begin_
			end_ :
		mov n, ecx
	}

	return n;
}