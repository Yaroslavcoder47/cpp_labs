#pragma once
#ifndef PARSER_H
#define PARSER_H
#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class Parser
{
public:
	void parseData(std::string file, bool flag);
	//std::map<std::string, double> parseCode(std::string file);
private:
	void clearString(std::string& str);
};

#endif // !PARSER_H