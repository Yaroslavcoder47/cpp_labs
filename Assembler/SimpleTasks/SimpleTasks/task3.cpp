#include "task3.h"
auto logger3 = spdlog::basic_logger_mt("Lab03_task3", "../Logs/Lab03Logger.txt");

int task3(int a, int n)
{
	logger3->set_level(spdlog::level::debug);
	logger3.get()->debug("Function task3 work");
	int res = 0;
	__asm {
		mov eax, n // степень
		mov ebx, 1 // результат
		mov edx, a // число, которое возводится в степень
		mov ch, 2
		_loop:
			cmp eax, 0
			je _end
			test eax, 1
			jnz _noteven
			div ch
			imul edx, edx
			jmp _loop
		_noteven:
			dec eax
			imul ebx, edx
			jmp _loop
		_end:
			mov res, ebx
	}
	return res;
}