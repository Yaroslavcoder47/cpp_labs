#pragma once
#ifndef PROGRAM_CLASS_H
#define PROGRAM_CLASS_H
#include <spdlog/spdlog.h>
#include <map>
#include <vector>
#include <string>
#include "Parser.h"

using std::cin;
using std::cout;
using std::string;
using std::map;
using std::vector;

class ProgramClass
{
public:
	static int Calculate();
	void setData();
private:
	std::map<std::string, int> dataNumber;
};

#endif // !PROGRAM_CLASS_H