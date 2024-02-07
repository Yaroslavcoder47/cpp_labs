#pragma once
#ifndef PARSER_H
#define PARSER_H
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

class Parser
{
public:
	std::map<std::string, int> parseData(const std::string& file, bool flag);
	void parseCode(std::string, ProgramClass&);
private:
	void clearString(std::string& str);
};

#endif // !PARSER_H