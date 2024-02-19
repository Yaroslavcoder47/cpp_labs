#include "Task2.h"

int task2(int a)
{
	int res = 0;
	__asm {
		mov eax, a
		mul eax
		mov ebx, eax
		sub ebx, 4
		imul ebx, 2
		mul eax
		imul eax, a
		add eax, ebx
		add eax, a
		mov ebx, a
		imul ebx, a
		imul ebx, a
		div ebx
		mov res, eax
	}

	return res;
}