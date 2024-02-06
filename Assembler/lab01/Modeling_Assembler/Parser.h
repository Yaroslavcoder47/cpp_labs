#pragma once
#ifndef PARSER_H
#define PARSER_H
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

class Parser
{
public:
	std::map<std::string, int> parseData(const std::string& file, bool flag);
	std::map<std::string, std::string> parseCode(std::string file);
private:
	void clearString(std::string& str);
};

#endif // !PARSER_H