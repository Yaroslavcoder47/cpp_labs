#pragma once
#ifndef PROGRAM_CLASS_H
#define PROGRAM_CLASS_H
#include <spdlog/spdlog.h>
#include <map>
#include <vector>
#include <string>
#include <fstream>
#include "Parser.h"
#include "Command.h"

using std::cin;
using std::cout;
using std::string;
using std::map;
using std::vector;

class ProgramClass
{
public:
	static int Calculate();
	void parseCode(std::string file, ProgramClass& obj);
	void setRegisterData(int data) { EAX = data; };
	void setResultData(std::string key, int value) { dataResult[key] = value; };
	int getRegisterData() { return EAX; };
	int getResultData(std::string key) { return dataResult[key]; };
	int getDataNumber(std::string key) { return dataNumber[key]; };
	void printData(std::string file);
private:
	std::map<std::string, int> dataNumber;
	std::map<std::string, int> dataResult;
	int EAX;
};

#endif // !PROGRAM_CLASS_H