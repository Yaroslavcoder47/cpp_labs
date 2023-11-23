#pragma once
#ifndef COUNTRIESPOPULATION__PROGRAMCOUNTRIESPOPULATION_H_
#define COUNTRIESPOPULATION__PROGRAMCOUNTRIESPOPULATION_H_
#include <fstream>
#include <iostream>
#include <sstream>
#include <set>
#include "WorldPopulation.h"
#include "CountryFeature.h"
#include "WorldCountry.h"
#include "WorldRegionPopulation.h"

class ProgramCountriesPopulation {
public:
	WorldPopulation worldPopulation;
	std::vector<CountryFeature> countryFeature;
	std::vector<WorldCountry> worldCountry;
	std::set<std::string> uniqueRegions;
	std::vector<WorldRegionPopulation> worldRegionPopulation;
	static int main();
	void readCountryPopulationFromFile(std::string file);
	void writeWorldPopulationToFile(std::string filePath, char delimetr);
	void readCountryFeature(std::string filePath);
	void readCountryFeaturePopulationFromFile(std::string filePath);
	std::vector<WorldCountry> chooseCountryIcome(std::string levelOfIncome);
	std::vector<WorldCountry> chooseCountryRegion(std::string countryRegion);
	std::set<std::string> makeUniqueCollectionOfRegions();
	std::vector<WorldRegionPopulation> CalcWorldRegionPopulation(); // function to calculate world population for region
	void writeWorldRegionPopulationToFile(std::string file);

	void writeToConsole();

};

#endif //COUNTRIESPOPULATION__PROGRAMCOUNTRIESPOPULATION_H_
