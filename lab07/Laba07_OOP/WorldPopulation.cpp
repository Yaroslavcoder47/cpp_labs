#include "WorldPopulation.h"
#include <fstream>
#include <sstream>
#include <iostream>


void WorldPopulation::calcWorldPopulation()
{
	for (auto& [year, population] : totalYearPopulation) {
		for (auto& country : countries) {
			population += country.yearPopulation[year];
		}
		//std::cout << year << ' ' << population << '\n'; // DEBUG in concole
	}
}

