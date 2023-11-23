#pragma once
#ifndef WorldRegionPopulation_H 
#define WorldRegionPopulation_H

#include <string>
#include <map>
#include <vector>
#include "WorldCountry.h"

struct WorldRegionPopulation
{
	std::string region;
	std::map<int, long long int> yearPopulationRegion;
};
#endif // WorldRegionPopulation 



