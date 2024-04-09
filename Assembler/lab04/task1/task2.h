#pragma once
#ifndef TASK2_H
#define TASK2_H

#include <vector>
#include <algorithm>
#include "spdlog/spdlog.h"

std::vector<int> mergeArrays(int* ptrA, int* ptrB, int aSize, int bSize) {

	spdlog::trace("mergeArrays func. started.");
	spdlog::debug("__asm started.");
	std::vector<int> res;
	int resSize = aSize + bSize;
	int* c = new int[resSize];

	__asm {
		xor edx, edx
		xor ebx, ebx
		
		mov edi, dword ptr[c]
		mov esi, 0
		mergeLoop_:
			cmp edx, aSize
			jge firstLoop_
			cmp ebx, bSize
			jge firstLoop_
			mov ecx, dword ptr[ptrA]
			mov eax, dword ptr[ecx + edx * 4]
			mov ecx, dword ptr[ptrB]
			cmp eax, dword ptr[ecx + ebx * 4]
			jle fElse_
			mov ecx, dword ptr[ptrB]
			mov eax, dword ptr[ecx + ebx * 4]
			mov dword ptr[edi + esi * 4], eax
			inc esi
			inc ebx
			jmp mergeLoopCont_
		fElse_:
			mov ecx, dword ptr[ptrA]
			mov eax, dword ptr[ecx + edx * 4]
			mov dword ptr[edi + esi * 4], eax
			inc edx
			inc esi
		mergeLoopCont_:
			jmp mergeLoop_
		
		firstLoop_:
			cmp edx, aSize
			jge secondLoop_
			mov ecx, dword ptr[ptrA]
			mov eax, dword ptr[ecx + edx * 4]
			mov dword ptr[edi + esi * 4], eax
			inc edx
			inc esi
			jmp firstLoop_
		secondLoop_:
			cmp ebx, bSize
			jge end_
			mov ecx, dword ptr[ptrB]
			mov eax, dword ptr[ecx + ebx * 4]
			mov dword ptr[edi + esi * 4], eax
			inc esi
			inc ebx
			jmp secondLoop_
		end_:
	}
	for (size_t i = 0; i < aSize + bSize; ++i) {
		res.push_back(c[i]);
	}

	return res;
}
//code on C++
/*while (!a.empty() && !b.empty()) {
		if (a[0] > b[0]) {
			res.push_back(b[0]);
			b.erase(b.begin(), b.begin() + 1);
		}
		else {
			res.push_back(a[0]);
			a.erase(a.begin(), a.begin() + 1);
		}
	}
	while (!a.empty()) {
		res.push_back(a[0]);
		a.erase(a.begin(), a.begin() + 1);
	}
	while (!b.empty()) {
		res.push_back(b[0]);
		b.erase(b.begin(), b.begin() + 1);
	}*/

#endif // !TASK2_H