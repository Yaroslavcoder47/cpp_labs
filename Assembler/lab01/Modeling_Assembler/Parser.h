#pragma once
#ifndef PARSER_H
#define PARSER_H
#include <map>
#include <string>

class Parser
{
public:
	std::map<std::string, double> parseData(std::string file);
	std::map<std::string, double> parseCode(std::string file);
};

#endif // !PARSER_H