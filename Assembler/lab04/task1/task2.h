#pragma once
#ifndef TASK2_H
#define TASK2_H

#include <vector>
#include <algorithm>
#include "spdlog/spdlog.h"

std::vector<int> mergeArrays(int* ptrA, int* ptrB, int aSize, int bSize) {

	//spdlog::trace("mergeArrays func. started.");
	//spdlog::debug("__asm started.");

	std::vector<int> res;
	std::vector<int> g = { 11 };

	int resSize = aSize + bSize;

	//std::cout << *ptrA << " " << *ptrB << std::endl;

	int* c = new int[resSize];

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

	__asm {
		xor edx, edx
		xor ebx, ebx
		//mov edx, dword ptr [ptrA]
		//mov ebx, dword ptr [ptrB]
		
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
			mov eax, dword ptr[ptrA + edx * 4]
			mov dword ptr[edi + esi * 4], eax
			inc edx
			inc esi
		mergeLoopCont_:
			jmp mergeLoop_
		
		firstLoop_:
			cmp edx, aSize
			jge secondLoop_
			mov eax, dword ptr[ptrA + edx * 4]
			mov dword ptr[edi + esi * 4], eax
			inc edx
			inc esi
			jmp firstLoop_
		secondLoop_:
			cmp ebx, bSize
			jge end_
			mov eax, dword ptr[ptrB + ebx * 4]
			mov dword ptr[edi + esi * 4], eax
			inc esi
			inc ebx
			jmp secondLoop_
		end_:
	}
	for (size_t i = 0; i < aSize + bSize; ++i) {
		std::cout << c[i] << ' ';
	}

	return res;
}

#endif // !TASK2_H



//#pragma once
//#include "spdlog/sinks/basic_file_sink.h"
//#include <vector>
//
//
//
//
//std::vector<int> mergeAsm(std::vector<int> first, std::vector<int> second) {
//    
//    int* a = first.data();
//    int* b = second.data();
//    int n = first.size();
//    int m = second.size();
//    int* c = new int[n + m];
//    std::vector<int> ans;
//    int _length = n + m;
//    bool ok = 0;
//    __asm {
//        xor edx, edx
//        mov edi, dword ptr[c]
//        mov ecx, 0
//        mov eax, 0
//        mov ebx, 0
//        cmp m, 0
//        je _end1
//        _mergeArrays :
//        cmp ecx, _length
//            je _end
//            cmp eax, n
//            je _elsePart
//            cmp ebx, m
//            je _ifPart
//            mov esi, dword ptr[b]
//            mov edx, dword ptr[esi + ebx * 4]
//            mov esi, dword ptr[a]
//            cmp dword ptr[esi + eax * 4], edx
//            jl _ifPart
//            jmp _elsePart
//            _ifPart :
//        mov esi, dword ptr[a]
//            mov edx, dword ptr[esi + eax * 4]
//            mov dword ptr[edi + ecx * 4], edx
//            inc eax
//            inc ecx
//            jmp _mergeArrays
//            _elsePart :
//        cmp ebx, m
//            je _mergeArrays
//            mov esi, dword ptr[b]
//            mov edx, dword ptr[esi + ebx * 4]
//            mov dword ptr[edi + ecx * 4], edx
//            inc ebx
//            inc ecx
//            jmp _mergeArrays
//            _end1 :
//        mov ok, 1
//            _end :
//    }
//   
//    if (ok)
//        return first;
//    for (int i = 0; i < n + m; i++) {
//        ans.push_back(c[i]);
//    }
//    delete[] c;
//
//    return ans;
//}