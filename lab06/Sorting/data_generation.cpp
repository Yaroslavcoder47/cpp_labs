#include <string>
#include <vector>
#include <iostream>
#include "iodata.h"
#include "data_generation.h"


std::vector<int> generateDataAscending(size_t amount)
{
	std::vector <int> list(amount);
	for (size_t i = 0; i < amount; ++i) {
		list[i] = i;
	}
	return list;
}

std::vector<int> generateDataDescending(size_t amount)
{
	std::vector<int> list(amount);
	int i = 0;
	for (auto iterator = list.rbegin(); iterator != list.rend(); ++iterator, ++i) {
		*iterator = i;
	}
	return list;
}

std::vector<int> generateDataRandom(size_t amount, int n)
{
	std::vector<int> list(amount);
	srand(time(NULL));
	for (auto& item : list) {
		item = rand() % n + 1;
	}
	return list;
}