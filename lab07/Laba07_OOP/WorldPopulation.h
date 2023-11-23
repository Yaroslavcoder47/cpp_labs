#pragma once
#ifndef WORLD_POPULATION_H
#define WORLD_POPULATION_H

#include <vector>
#include "Country.h"

struct WorldPopulation
{
	std::vector<Country> countries;
	std::map<int, long long int> totalYearPopulation;
	void calcWorldPopulation(); //write into totalYearPopulation
};

#endif //WORLD_POPULATION_H



