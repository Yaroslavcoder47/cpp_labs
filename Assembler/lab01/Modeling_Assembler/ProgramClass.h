#pragma once
#ifndef PROGRAM_CLASS_H
#define PROGRAM_CLASS_H
#include "spdlog/spdlog.h"
#include <map>
#include <string>
#include <fstream>
#include "Parser.h"
#include "Command.h"
#include "Multiplication.h"
#include "Division.h"
#include "Addition.h"
#include "Subtraction.h"

using std::cin;
using std::cout;
using std::string;
using std::map;


class ProgramClass
{
public:
	static int main();
	void parseCode(std::string file, ProgramClass& obj);
	void setRegisterData(int data) { EAX = data; };
	void setResultData(std::string key, int value) { dataResult[key] = value; };
	int getRegisterData() { return EAX; };
	int getResultData(std::string key) { return dataResult[key]; };
	int getDataNumber(std::string key) { return dataNumber[key]; };
	void printData(std::string file);
private:
	int executeCommand(Command* cmd);
	std::map<std::string, int> dataNumber;
	std::map<std::string, int> dataResult;
	int EAX;
};

#endif !PROGRAMCLASS_H