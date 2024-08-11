#include "ProgramCountriesPopulation.h"


void operator<<(std::ostream& stream, const std::vector<CountryFeature>& container)
{
	for (const auto it : container) {
		stream << it.countryCode << ' ' << it.region << ' ' << it.incomeGroup << '\n';
	}   
}

void operator<<(std::ostream& stream, const Country& country)
{
	stream << country.toString();
}

int ProgramCountriesPopulation::main() {
	try {
		ProgramCountriesPopulation wp;
		wp.readCountryPopulationFromFile("data/world_population_1960-2018.csv");
		wp.worldPopulation.calcWorldPopulation();
		wp.writeWorldPopulationToFile("data/worldPopulation.csv", ';');
		wp.readCountryFeature("data/countries.csv");
		wp.readCountryFeaturePopulationFromFile("data/countries1.csv");

		wp.uniqueRegions = wp.makeUniqueCollectionOfRegions();
		wp.worldRegionPopulation = wp.CalcWorldRegionPopulation();
		wp.writeWorldRegionPopulationToFile("data/regionPopulation.csv");
		
		//wp.writeToConsole(); //DEBUG to check read data
		return 0;
	}
	catch (std::invalid_argument& ex) {
		std::cerr << ex.what();
	}
	return 0;
}

void ProgramCountriesPopulation::readCountryPopulationFromFile(std::string file)
{
	std::vector <std::string> list;
	std::string str;
	std::ifstream fin(file, std::ios::in);
	while (!fin.eof()) {
		getline(fin, str);
		//fin >> str;
		//std::cout << str << '\n'; DEBUG
		if (str != "") {
			list.push_back(str);
		}
	}
	fin.close();
	//std::cout << list[list.size()-1] << '\n';  DEBUG
	//std::cout << list.size();   DEBUG

	//string parcing
	//first string contains the names of columns of data
	std::stringstream ss(list.at(0));
	//std::cout << list.at(0); DEBUG
	getline(ss, str, ';');
	if (str != "Country Name") {
		throw std::invalid_argument("File contains wrong data");
	}
	getline(ss, str, ';');
	if (str != "Country Code") {
		throw std::invalid_argument("File contains wrong data");
	}
	int year;
	char ch;
	std::vector <int> years;
	while (!ss.eof()) {
		//read a year and ";" sign
		ss >> year >> ch;
		//std::cout << year << ' '; DEBUG
		years.push_back(year);
		worldPopulation.totalYearPopulation[year] = 0; //overall world population
	}
	//get data about each country
	int population;
	for (size_t i = 1; i < list.size(); ++i) {
		std::stringstream ssCountry(list.at(i));
		Country country;
		getline(ssCountry, country.name, ';');
		//std::cout << country.name << ' '; DEBUG
		getline(ssCountry, country.code, ';');
		int count = 0;
		std::string tmp;

		//while (!ssCountry.eof()) { // Not work. put 0 to last value of population in 2018 year
		while (getline(ssCountry, tmp, ';')) {
			//while (ssCountry >> population >> ch) {
				//ssCountry >> population >> ch; 
			//getline(ssCountry, tmp, ';');
			if (tmp != "") {
				population = std::stoll(tmp);
			}
			else {
				population = 0;
			}
			//std::cout << population << '\n';
			/*try {
				ssCountry >> population >> ch;
			}
			catch (...) {
				population = 0;
			}*/
			/*std::pair yearPopulation = {years[count], population};
			country.yearPopulation.insert(yearPopulation);*/ //1st way
			//std::cout << population << '\n'; DEBUG
			country.yearPopulation[years[count]] = population; //2nd way
			++count;
		}
		worldPopulation.countries.push_back(country);
	}
}

void ProgramCountriesPopulation::writeWorldPopulationToFile(std::string filePath, char delimetr)
{
	std::ofstream fout(filePath, std::ios::out);
	std::string stringOfYears;
	std::string stringOfPopulation;
	for (const auto& item : worldPopulation.totalYearPopulation) {
		stringOfYears += std::to_string(item.first) + ';';
		stringOfPopulation += std::to_string(item.second) + ';';
	}
	fout << stringOfYears << '\n';
	fout << stringOfPopulation;
	fout.close();
}

void ProgramCountriesPopulation::readCountryFeature(std::string filePath)
{
	//std::vector<CountryFeature> countries;
	std::vector <std::string> list;
	std::string str;
	std::ifstream fin(filePath, std::ios::in);
	while (!fin.eof()) {
		getline(fin, str);
		list.push_back(str);
	}
	fin.close();

	std::stringstream ss(list.at(0));
	getline(ss, str, ';');
	if (str != "Country Code") {
		throw std::invalid_argument("File contains wrong data");
	}
	getline(ss, str, ';');
	if (str != "Region") {
		throw std::invalid_argument("File contains wrong data");
	}
	getline(ss, str, ';');
	if (str != "IncomeGroup") {
		throw std::invalid_argument("File contains wrong data");
	}
	getline(ss, str, ';');
	if (str != "Country Name") {
		throw std::invalid_argument("File contains wrong data");
	}

	std::string code;
	std::string region;
	std::string income;
	std::string name;

	for (size_t i = 1; i < list.size(); ++i) {
		CountryFeature country;
		std::stringstream ssCountry(list.at(i));
		std::getline(ssCountry, code, ';');
		std::getline(ssCountry, region, ';');
		std::getline(ssCountry, income, ';');
		std::getline(ssCountry, name, ';');
		country.countryCode = code;
		country.region = region;
		country.incomeGroup = income;
		countryFeature.push_back(country);
	}
}

void ProgramCountriesPopulation::readCountryFeaturePopulationFromFile(std::string filePath)
{
	std::vector <std::string> list;
	std::string str;
	std::ifstream fin(filePath, std::ios::in);
	while (!fin.eof()) {
		getline(fin, str);
		if (str != "") {
			list.push_back(str);
		}
	}
	fin.close();

	std::stringstream ss(list.at(0));
	getline(ss, str, ';');
	if (str != "Country Code") {
		throw std::invalid_argument("File contains wrong data");
	}
	getline(ss, str, ';');
	if (str != "Region") {
		throw std::invalid_argument("File contains wrong data");
	}
	getline(ss, str, ';');
	if (str != "IncomeGroup") {
		throw std::invalid_argument("File contains wrong data");
	}
	getline(ss, str, ';');
	if (str != "Country Name") {
		throw std::invalid_argument("File contains wrong data");
	}
	getline(ss, str, ';');
	if (str != "Country Code") {
		throw std::invalid_argument("File contains wrong data");
	}

	int year;
	char ch;
	std::vector <int> years;
	while (!ss.eof()) {
		ss >> year >> ch;
		years.push_back(year);
	}

	int population;
	for (size_t i = 1; i < list.size(); ++i) {
		std::stringstream ssCountry(list.at(i));
		WorldCountry wc;
		std::string templ;
		getline(ssCountry, templ, ';');
		getline(ssCountry, templ, ';');
		getline(ssCountry, templ, ';');
		wc.countryFeature = countryFeature[i - 1];
		getline(ssCountry, wc.countryName, ';');
		getline(ssCountry, templ, ';');

		int count = 0;

		while (getline(ssCountry, templ, ';')) {
			if (templ != "") {
				population = std::stoll(templ);
			}
			else {
				population = 0;
			}
			wc.yearPopulation[years[count]] = population;
			++count;
		}
		
		worldCountry.push_back(wc);
	}
}

void ProgramCountriesPopulation::writeToConsole()
{
	for (const auto y : worldCountry)
	{
		std::cout << y.countryName << ' ' << y.countryFeature.countryCode << ' ' << y.countryFeature.incomeGroup <<
			' ' << y.countryFeature.region << '\n';
	}
}

std::vector<WorldCountry> ProgramCountriesPopulation::chooseCountryIcome(std::string levelOfIncome)
{
	std::vector<WorldCountry> container;
	for (const auto& country : worldCountry){
		if (country.countryFeature.incomeGroup == levelOfIncome){
			container.push_back(country);
		}
	}
	return container;
}

std::vector<WorldCountry> ProgramCountriesPopulation::chooseCountryRegion(std::string countryRegion)
{
	std::vector<WorldCountry> container;
	for (const auto& country : worldCountry){
		if (country.countryFeature.region == countryRegion){
			container.push_back(country);
		}
	}
	return container;
}

std::set<std::string> ProgramCountriesPopulation::makeUniqueCollectionOfRegions()
{
	std::set<std::string> container;
	for (const auto& country : countryFeature) {
		container.insert(country.region);
	}
	return container;
}

std::vector<WorldRegionPopulation> ProgramCountriesPopulation::CalcWorldRegionPopulation()
{
	std::vector<WorldRegionPopulation> container;
	for (const auto& iter : uniqueRegions) {
		WorldRegionPopulation wp;
		wp.region = iter;
		for (const auto& country : worldCountry) {
			if (country.countryFeature.region == iter) {
				for (auto [year, population] : country.yearPopulation) {
					wp.yearPopulationRegion[year] += population;
				}
			}
		}
		container.push_back(wp);
	}
	return container;
}

void ProgramCountriesPopulation::writeWorldRegionPopulationToFile(std::string file)
{
	std::ofstream fout(file, std::ios::out);
	std::string firstString;
	std::string secondString;
	firstString = "Region;";
	for (const auto& [year, population] : worldRegionPopulation[0].yearPopulationRegion) {
		firstString += std::to_string(year) + ";";
	}
	fout << firstString << '\n';
	for (const auto& region : worldRegionPopulation) {
		secondString = region.region + ";";
		for (const auto& [year, population] : region.yearPopulationRegion) {
			secondString += std::to_string(population) + ";";
		}
		fout << secondString << '\n';
	}
	fout.close();
}