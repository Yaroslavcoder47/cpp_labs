#pragma once
#ifndef TASK3_H
#define TASK3_H

#include <vector>
#include <algorithm>
#include "spdlog/spdlog.h"

bool arrayIntersection(std::vector<int>& a, std::vector<int>& b, std::vector<int>& c) 
{
	int* ptrA = a.data();
	int* ptrB = b.data();
	int aSize = a.size();
	int bSize = b.size();
	 // доделать с выделением памяти
	std::vector<int>* res = new std::vector<int>();
	//int* ptrRes = res.data();

	__asm {
		xor edx, edx
		xor ebx, ebx

		mov esi, 0
		//mov edi, ptrRes
		mov edi, dword ptr[res]
		firstLoop_:
			cmp edx, aSize
			jge end_
			xor ebx, ebx
		secondLoop_:	
			cmp ebx, bSize
			jge firstLoopCont_
			mov eax, dword ptr[ptrA]
			mov ecx, dword ptr[eax + edx * 4]
			mov eax, dword ptr[ptrB]
			cmp ecx, dword ptr[eax + ebx * 4]
			je pushElem_
			inc ebx
			jmp secondLoop_

		pushElem_:
			mov dword ptr[edi + esi * 4], ecx
			inc esi
			inc ebx
			jmp firstLoopCont_
		firstLoopCont_:
			inc edx
			jmp firstLoop_
		end_:
	}
	for (size_t i = 0; i < res->size(); ++i) {
		std::cout << *(res->begin()+1) << ' ';
	}
	/*for (auto it : res) {
		std::cout << it << ' ';
	}
	sort(res.begin(), res.end());
	if (res.size() != c.size()) {
		return 0;
	}
	for (size_t i = 0; i < res.size(); ++i) {
		std::cout << res[i] << ' ';
		if (res[i] != c[i]) {
			return 0;
		}
	}*/
	return 1;

}

#endif // !TASK3_H
