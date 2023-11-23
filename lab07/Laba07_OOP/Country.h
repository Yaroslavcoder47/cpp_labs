#pragma once
#ifndef COUNTRY_H_
#define COUNTRY_H_

#include <string>
#include <map>
struct Country
{
	std::string name;
	std::string code;
	std::map<int, long long int> yearPopulation; 
	std::string toString() const;
};

#endif //COUNTRY_H_