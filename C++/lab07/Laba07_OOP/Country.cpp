#include "Country.h"

//country_name (country_code): population[YYYY], population[YYYY], ...
std::string Country::toString() const
{
	std::string str = name + " (" + code + "): ";
	for (const auto& [year, population] : yearPopulation) {
		str += std::to_string(population) + "[" + std::to_string(year) + "], ";
	}
	return str;
}