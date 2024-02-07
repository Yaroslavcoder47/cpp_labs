#include "ProgramClass.h"

int ProgramClass::Calculate()
{
	ProgramClass program;
	Parser pars;
	program.dataNumber = pars.parseData("input.txt", 1);
	
	for (const auto& i : program.dataNumber) {
		std::cout << i.first << " " << i.second << "\n";
	}
	program.dataResult = pars.parseData("input.txt", 0);
	pars.parseCode("input.txt");
	
	return 0;
}

void Parser::parseCode(std::string file)
{
	Parser pars;
	std::map<std::string, std::string> list;
	std::string arg1;
	std::string arg2;
	std::string ch;
	std::string str;
	std::ifstream fin(file, std::ios::in);
	while (getline(fin, str), str != ".code") {
		continue;
	}
	while (getline(fin, str), str != "end") {
		pars.clearString(str);
		std::stringstream ss(str);
		ss >> arg1 >> ch >> arg2;

	}
	fin.close();
}
