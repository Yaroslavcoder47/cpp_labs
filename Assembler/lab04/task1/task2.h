#pragma once
#ifndef TASK2_H
#define TASK2_H

int f() {
	int i = 1;
	__asm {
		mov ecx, 4;
	forloop:
		inc i
			loop forloop
	}
	return i;
}



#endif // !TASK2_H

