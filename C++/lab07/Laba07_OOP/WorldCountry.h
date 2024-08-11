#pragma once
#ifndef WORLD_COUNTRY_H
#define WORLD_COUNTRY_H

#include <string>
#include <map>
#include "CountryFeature.h"
#include "WorldCountry.h"

class WorldCountry
{
public:
	std::string countryName;	
	CountryFeature countryFeature;
	std::map<int, long long int> yearPopulation;
};
#endif // WORLD_COUNTRY_H




