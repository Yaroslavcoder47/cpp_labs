#include "Task4.h"


std::vector<uint16_t> task4(uint16_t a1, uint16_t a2, uint16_t a3, uint16_t b1, uint16_t b2, uint16_t b3)
{
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