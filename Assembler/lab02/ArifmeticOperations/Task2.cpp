#include "Task2.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

auto logger2 = spdlog::basic_logger_mt("Lab02_task2", "Lab02Logger.txt");

int task2(int a)
{
	logger2.get()->debug("Function task2 started");
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