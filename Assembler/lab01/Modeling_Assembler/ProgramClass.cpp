#include "ProgramClass.h"


int ProgramClass::Calculate()
{
	try {
		spdlog::set_level(spdlog::level::debug);
		spdlog::info("Start");

		ProgramClass program;
		Parser pars;
		program.dataNumber = pars.parseData("input-asm-code.txt", 1);
		program.dataResult = pars.parseData("input-asm-code.txt", 0);
		program.parseCode("input-asm-code.txt", program);
		program.printData("output.json");

		spdlog::info("End");
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what();
	}
	return 0;
}

void ProgramClass::printData(std::string file)
{
	spdlog::debug("Output data in file");
	std::ofstream fout(file, std::ios::out);
	if (file == "output.json") {
		spdlog::info("Output data in JSON file");
		fout << "{ ";
		for (const auto& item : dataResult) {
			fout << '\"' << item.first << "\":" << item.second << ", ";
		}
		fout << '}';
	}
	if (file == "output.txt") {
		spdlog::info("Output data in TXT file");
		for (const auto& item : dataResult) {
			fout << item.first << ' ' << item.second << '\n';
		}
	}
}

//TODO much easier with if
void ProgramClass::parseCode(std::string file, ProgramClass& obj)
{
	spdlog::debug("Parsing part of .code");
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
