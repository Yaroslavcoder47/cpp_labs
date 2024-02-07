#include "ProgramClass.h"

int ProgramClass::Calculate()
{
	ProgramClass program;
	program.setData();
	for (const auto& i : program.dataNumber) {
		std::cout << i.first << " " << i.second << "\n";
	}
	
	return 0;
}

void ProgramClass::setData()
{
	Parser pars;
	dataNumber = pars.parseData("input.txt", 1);
}
