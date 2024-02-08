#include "Parser.h"

void Parser::clearString(std::string& str) {
	spdlog::debug("Clear string of comments");
	for (size_t i = 0; i < str.length(); ++i) {
		if (str[i] == '/') {
			if (str[i+1] == '*') {
				int j = i;
				++i;
				while (str[i] != '/') {
					++i;
				}
				str.erase(j, i - j + 1);
				i = j - 1;
				continue;
			}
			str = str.substr(0, i);
		
		}	
	}
}

std::map<std::string, int> Parser::parseData(const std::string& file, bool flag)
{
	spdlog::debug("Parsing part of .data");
	std::map<std::string, int> list;
	std::string arg1;
	std::string arg2s;
	int arg2;
	std::string str;
	std::ifstream fin(file, std::ios::in);
	while (getline(fin, str), str != ".code") {
		if (str != ".data") {
			clearString(str);
			std::stringstream ss(str);
			ss >> arg1 >> arg2s;
			if (flag) {
				if (arg2s != "?") {
					arg2 = std::stoi(arg2s);
					list[arg1] = arg2;
				}
			}
			else {
				if (arg2s == "?") {
					list[arg1] = 0;
				}
			}
			
			
		}
	}
	fin.close();
	return list;
}