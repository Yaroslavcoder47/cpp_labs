#include "Task3.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

auto logger3 = spdlog::basic_logger_mt("Lab02_task3", "Lab02Logger.txt");

int task3(unsigned int a)
{
	logger3.get()->debug("Function task3 started");
	int n = 1;
	__asm {
		mov ecx, 1
		mov eax, a
		jo end_
		begin_ :
		imul a
			jo end_
			add ecx, 1
			jmp begin_
			end_ :
		mov n, ecx
	}

	return n;
}