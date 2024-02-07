#include "ProgramClass.h"

//TODO add tests and log
int ProgramClass::Calculate()
{
	ProgramClass program;
	Parser pars;
	program.dataNumber = pars.parseData("input-asm-code.txt", 1);
	program.dataResult = pars.parseData("input-asm-code.txt", 0);
	program.parseCode("input-asm-code.txt", program);
	program.printData("output.txt");
	return 0;
}

void ProgramClass::printData(std::string file)
{
	std::ofstream fout(file, std::ios::out);
	if (file == "output.json") {
		fout << "{ ";
		for (const auto& item : dataResult) {
			fout << '\"' << item.first << "\":" << item.second << ", ";
		}
		fout << '}';
	}
	if (file == "output.txt") {
		for (const auto& item : dataResult) {
			fout << item.first << ' ' << item.second << '\n';
		}
	}
	
}

//TODO much easier with if
void ProgramClass::parseCode(std::string file, ProgramClass& obj)
{
	Parser pars;
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
		
		if (arg1 == "mul") {
			if (ch == "Ak") {
				if (dataNumber.find(arg2) == dataNumber.end()) {
					obj.setRegisterData(Command::multiplication(obj.getRegisterData(), obj.getResultData(arg2)));
				}
				else {
					obj.setRegisterData(Command::multiplication(obj.getRegisterData(), obj.getDataNumber(arg2)));
				}
			}
			else {
				obj.setResultData(ch, Command::multiplication(obj.getRegisterData(), obj.getDataNumber(arg2)));
			}
		}
		if (arg1 == "add") {
			if (ch == "Ak") {
				if (dataNumber.find(arg2) == dataNumber.end()) {
					obj.setRegisterData(Command::addition(obj.getRegisterData(), obj.getResultData(arg2)));
				}
				else {
					obj.setRegisterData(Command::addition(obj.getRegisterData(), obj.getDataNumber(arg2)));
				}
			}
			else {
				obj.setResultData(ch, Command::addition(obj.getRegisterData(), obj.getDataNumber(arg2)));
			}
		}
		if (arg1 == "div") {
			if (ch == "Ak") {
				if (dataNumber.find(arg2) == dataNumber.end()) {
					obj.setRegisterData(Command::division(obj.getRegisterData(), obj.getResultData(arg2)));
				}
				else {
					obj.setRegisterData(Command::division(obj.getRegisterData(), obj.getDataNumber(arg2)));
				}
			}
			else {
				obj.setResultData(ch, Command::division(obj.getRegisterData(), obj.getDataNumber(arg2)));
			}
		}
		if (arg1 == "sub") {
			if (ch == "Ak") {
				if (dataNumber.find(arg2) == dataNumber.end()) {
					obj.setRegisterData(Command::subtraction(obj.getRegisterData(), obj.getResultData(arg2)));
				}
				else {
					obj.setRegisterData(Command::subtraction(obj.getRegisterData(), obj.getDataNumber(arg2)));
				}
			}
			else {
				obj.setResultData(ch, Command::subtraction(obj.getRegisterData(), obj.getDataNumber(arg2)));
			}
		}
		if (arg1 == "mov") {
			if (ch == "Ak") {
				obj.setRegisterData(obj.getDataNumber(arg2));
			}
			else {
				obj.setResultData(ch, obj.getRegisterData());
			}
		}
	}
	fin.close();
}
