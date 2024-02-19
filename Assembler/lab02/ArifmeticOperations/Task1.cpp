#include "Task1.h"

int task1(int a)
{
	int res = 0;
	__asm {
		mov eax, a
		mul eax
		mov ebx, eax
		imul ebx, a
		mul eax
		imul eax, a
		add eax, ebx
		add eax, a
		mov res, eax
	}
	return res;
}