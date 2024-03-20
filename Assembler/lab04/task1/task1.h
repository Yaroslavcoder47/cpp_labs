#pragma once

#ifndef TASK1_H
#define TASK1_H

#include <vector>
#include "spdlog/spdlog.h"

void vectorRebuild(int* _ptr) {

	spdlog::trace("vectorRebuild func. started.");
	int i = 0;
	int _length = *_ptr;
	spdlog::debug("__asm started.");
	__asm {
		 mov edx, dword ptr[_ptr] // length begin of array
		 mov esi, 1 // var i
		 firstLoop_:
			cmp esi, dword ptr[edx]
			jge end_
			mov edi, dword ptr[edx] // var j
			jmp secondLoop_

		secondLoop_:
			cmp edi, esi
			jle firstLoopCont_
			mov ebx, dword ptr[edx + esi * 4]
			cmp ebx, dword ptr[edx + edi * 4]
			jne secondLoopCont_
			mov ecx, dword ptr[edx]
			sub ecx, edi // counter from j to k
			mov i, esi
			mov esi, edi
			dec dword ptr[edx]
			jmp thirdLoop_  // зашли в if и цикл for
		thirdLoop_:
			mov eax, dword ptr[edx + esi * 4 + 4]
			mov dword ptr[edx + esi * 4], eax
			loop thirdLoop_
			mov esi, i
			jmp secondLoopCont_
		secondLoopCont_:
			dec edi
			jmp secondLoop_
		firstLoopCont_:
			inc esi
			jmp firstLoop_
		end_:
	}

	/*__asm {
		mov edx, dword ptr[_ptr] // указатель на массив
		mov eax, dword ptr[edx] // edx = длине массива
		mov esi, 1
		firstLoopBegin_ :
			cmp esi, dword ptr[edx] // [edx] обращение к данным хранящимся в edx, т.е. к длине
			jl secondLoop_
			jmp end_
		secondLoop_ :
			mov edi, dword ptr[edx] // edi = length (j)

		secondLoopBegin_ :
			cmp edi, esi // j > i
			jg continueSecondLoop_
			inc esi // i++
			jmp firstLoopBegin_ // переход к i < length
		continueSecondLoop_ :
			mov ebx, dword ptr[edx + esi * 4] // length + i
			cmp ebx, dword ptr[edx + edi * 4]
			je thirdLoop_
			dec edi
			jmp secondLoopBegin_
		thirdLoop_ :
			mov ecx, dword ptr[edx] // ecx = length
			sub ecx, edi
			mov i, esi
			mov esi, edi
		thirdLoopBegin_ :
			mov ebx, [edx + esi * 4 + 4]
			mov [edx + esi * 4], ebx 
			inc esi
			loop thirdLoopBegin_
			dec dword ptr[edx]
			mov esi, i
			jmp secondLoopBegin_
		end_ :
	}*/

	spdlog::debug("__asm finished.");
	spdlog::trace("vectorRebuild func. finished.");
}

#endif //TASK1_H
//	mov ecx, dword ptr[edx] // ecx = length
		//	sub ecx, edi
		//	mov i, esi
		//	mov esi, edi
		//thirdLoopBegin_ :
		//	//mov eax, dword ptr[edx + esi * 4]
		//	mov ebx, [edx + esi * 4 + 4]
		//	mov[edx + esi * 4], ebx 
		//	
		//	dec dword ptr[edx]
		//	loop thirdLoopBegin_
		//	mov esi, i
		//	jmp secondLoopBegin_