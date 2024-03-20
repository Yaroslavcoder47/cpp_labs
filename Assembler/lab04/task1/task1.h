#pragma once
#ifndef TASK1_H
#define TASK1_H

#include "spdlog/spdlog.h"

void vectorRebuild(int* _ptr) {

	spdlog::trace("vectorRebuild func. started.");
	spdlog::debug("__asm started.");

	int i = 0;
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
			jmp thirdLoop_  // ����� � if � ���� for

		thirdLoop_:
			cmp ecx, 0
			je loopContinue_
			mov eax, dword ptr[edx + esi * 4 + 4]
			mov dword ptr[edx + esi * 4], eax
			dec ecx

		loopContinue_:
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

	spdlog::debug("__asm finished.");
	spdlog::trace("vectorRebuild func. finished.");
}
#endif //TASK1_H