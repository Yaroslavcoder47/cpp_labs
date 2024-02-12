#pragma once
#ifndef PARSER_H
#define PARSER_H

#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "ProgramClass.h"
#include "spdlog/spdlog.h"


class Parser
{
public:
	std::map<std::string, int> parseData(const std::string& file, bool flag);
	//friend void ProgramClass::parseCode(std::string file, ProgramClass& obj);
	void clearString(std::string& str);
};

#endif // !PARSER_H