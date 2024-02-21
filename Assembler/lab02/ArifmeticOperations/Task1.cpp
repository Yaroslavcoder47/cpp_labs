#include "Task1.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

auto logger1 = spdlog::basic_logger_mt("Lab02_task1", "Lab02Logger.txt");

int task1(int a)
{
	logger1.get()->debug("Function task1 started");
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