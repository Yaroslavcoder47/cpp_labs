#include "Task4.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"

auto logger4 = spdlog::basic_logger_mt("Lab02_task4", "Lab02Logger.txt");


std::vector<uint16_t> task4(uint16_t a1, uint16_t a2, uint16_t a3, uint16_t b1, uint16_t b2, uint16_t b3)
{
	logger4.get()->debug("Function task4 started");
	std::vector<uint16_t> result;
	uint32_t c1 = a1 + b1;
	uint32_t c2 = a2 + b2 + (c1 >> 16);
	uint32_t c3 = a3 + b3 + (c2 >> 16);
	result.push_back(static_cast<uint16_t>(c1));
	result.push_back(static_cast<uint16_t>(c2));
	result.push_back(static_cast<uint16_t>(c3));
	result.push_back(static_cast<uint16_t>(c3 >> 16));
	return result;
}

std::vector<uint16_t> task4Asm(uint16_t a1, uint16_t a2, uint16_t a3, uint16_t b1, uint16_t b2, uint16_t b3)
{
	logger4.get()->debug("Function task4Asm started");
	std::vector<uint16_t> result;
	uint32_t c1;
	uint32_t c2;
	uint32_t c3;
	
	__asm {
		mov ax, a1
		add ax, b1
		mov c1, ax

		mov ax, a2
		adc ax, b2
		mov c2, ax

		mov ax, a3
		adc ax, b3
		mov c3, ax
	}
	
	result.push_back(static_cast<uint16_t>(c1));
	result.push_back(static_cast<uint16_t>(c2));
	result.push_back(static_cast<uint16_t>(c3));
	result.push_back(static_cast<uint16_t>(c3 >> 16));
	return result;
}