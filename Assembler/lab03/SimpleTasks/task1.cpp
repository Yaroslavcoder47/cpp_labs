#include "task1.h"
auto logger1 = spdlog::basic_logger_mt("Lab03_task1", "../Logs/Lab03Logger.txt");

std::pair<int, int> task1(int num)
{
	logger1->set_level(spdlog::level::debug);
	logger1.get()->debug("Function task1 work");
	std::pair<int, int> res;
	uint8_t evenCounter = 0;
	uint8_t zeroCounter = 0;
	__asm {
		mov ebx, 0x000A
		xor ch, ch
		xor cl, cl
		mov eax, num
		mov edx, 0
		cmp eax, 0
		jl _abs
		jmp _loop
		_abs:
			neg eax
		_loop:
			cdq
			idiv ebx  // разделили на 10
			test edx, 1 // сравнили по маске на четность цифру
			jnz _check // если нечетная то проверяем на остаток цифр 
			inc ch // увеличиваем счетчик четных
			test edx, edx  // проверяем цифру на ноль
			jnz _check
			inc cl
			jmp _check
		_check:
			test eax, eax 
			jnz _loop // если в eax число 0, то цифр не осталось и переходим на метку _end
			jmp _end
		_end:
			mov evenCounter, ch
			mov zeroCounter, cl
	}
	res.first = static_cast<int>(evenCounter);
	res.second = static_cast<int>(zeroCounter);
	return res;
}