#include "task4.h"
auto logger4 = spdlog::basic_logger_mt("Lab03_task4", "../Logs/Lab03Logger.txt");

std::pair<int, int> task4(int num)
{
	logger4->set_level(spdlog::level::debug);
	logger4.get()->debug("Function task4 work");
	std::pair<int, int> res;
	int degree = 1;
	int tmp = 2;
	__asm {
		mov ecx, 0 // хранитс€ нижн€€ оценка степени двойки
		mov eax, 1 // переменна€ котора€ сравниваетс€ с num
		mov ebx, num
		_loop:
			cmp eax, ebx
			jg _end
			mul tmp
			inc ecx
			jmp _loop
		_end:
			mov degree, ecx
	}
	res.first = static_cast<int>(degree) - 1;
	res.second = static_cast<int>(degree);
	return res;
}