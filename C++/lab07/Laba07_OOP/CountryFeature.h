#pragma once
#ifndef COUNTRY_FEATURE_H
#define COUNTRY_FEATURE_H
#include <string>
#include <vector>

struct CountryFeature
{
	std::string countryCode;
	std::string region;
	std::string incomeGroup;
};

#endif //COUNTRY_FEATURE_H