#include "task2.h"
auto logger2 = spdlog::basic_logger_mt("Lab03_task2", "../Logs/Lab03Logger.txt");

std::pair<int, int> task2(int numerator, int denominator)
{
	logger2->set_level(spdlog::level::debug);
	logger2.get()->debug("Function task2 work");
	int gcd = 1;
	std::pair<int, int> res;
	__asm {
		mov eax, numerator
		mov ebx, denominator
		cmp eax, 0
		jl _abs
		jmp _loop
		_abs:
			neg eax
		_loop:
			cmp eax, ebx
			je _end
			jg _gr
			sub ebx, eax
			jmp _loop
		_gr:
			sub eax, ebx
			jmp _loop
		_end:
			mov gcd, eax
	}
	res.first = numerator / gcd;
	res.second = denominator / gcd;
	return res;
}