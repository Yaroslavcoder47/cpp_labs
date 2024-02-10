#include "ProgramClass.h"


int ProgramClass::main()
{
	try {
		spdlog::set_level(spdlog::level::debug);
		spdlog::info("Start");

		ProgramClass program;
		Parser pars;
		program.dataNumber = pars.parseData("input-asm-code.txt", 1);
		program.dataResult = pars.parseData("input-asm-code.txt", 0);
		program.parseCode("input-asm-code.txt", program);
		program.printData("output.txt");

		spdlog::info("End");
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what();
	}
	return 0;
}

int ProgramClass::executeCommand(Command* cmd)
{
	return cmd->execute();
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
		int result;
		if (arg1 == "mul") {
			if (ch == "Ak") {
				if (dataNumber.find(arg2) == dataNumber.end()) {
					result = getRegisterData();
					Command* mulCommand = new Multiplication(result, getResultData(arg2));
					setRegisterData(executeCommand(mulCommand));
				}
				else {
					result = getRegisterData();
					Command* mulCommand = new Multiplication(result, getDataNumber(arg2));
					setRegisterData(executeCommand(mulCommand));
				}
			}
			else {
				result = getRegisterData();
				Command* mulCommand = new Multiplication(result, getDataNumber(arg2));
				setResultData(ch, executeCommand(mulCommand));
			}
		}
		if (arg1 == "add") {
			if (ch == "Ak") {
				if (dataNumber.find(arg2) == dataNumber.end()) {
					result = getRegisterData();
					Command* addComand = new Addition(result, getResultData(arg2));
					setRegisterData(executeCommand(addComand));
				}
				else {
					result = getRegisterData();
					Command* addComand = new Addition(result, getDataNumber(arg2));
					setRegisterData(executeCommand(addComand));
				}
			}
			else {
				result = getRegisterData();
				Command* addComand = new Addition(result, getDataNumber(arg2));
				setResultData(ch, executeCommand(addComand));
			}
		}
		if (arg1 == "div") {
			if (ch == "Ak") {
				if (dataNumber.find(arg2) == dataNumber.end()) {
					result = getRegisterData();
					Command* divCommand = new Division(result, getResultData(arg2));
					setRegisterData(executeCommand(divCommand));
				}
				else {
					result = getRegisterData();
					Command* divCommand = new Division(result, getDataNumber(arg2));
					setRegisterData(executeCommand(divCommand));
				}
			}
			else {
				result = getRegisterData();
				Command* divCommand = new Division(result, getDataNumber(arg2));
				setResultData(ch, executeCommand(divCommand));
			}
		}
		if (arg1 == "sub") {
			if (ch == "Ak") {
				if (dataNumber.find(arg2) == dataNumber.end()) {
					result = getRegisterData();
					Command* subCommand = new Subtraction(result, getResultData(arg2));
					setRegisterData(executeCommand(subCommand));
				}
				else {
					result = getRegisterData();
					Command* subCommand = new Subtraction(result, getDataNumber(arg2));
					setRegisterData(executeCommand(subCommand));
				}
			}
			else {
				result = getRegisterData();
				Command* subCommand = new Subtraction(result, getDataNumber(arg2));
				setResultData(ch, executeCommand(subCommand));
			}
		}
		if (arg1 == "mov") {
			if (ch == "Ak") {
				setRegisterData(getDataNumber(arg2));
			}
			else {
				setResultData(ch, getRegisterData());
			}
		}
	}
	fin.close();
}
