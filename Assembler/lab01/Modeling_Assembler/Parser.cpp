#include "Parser.h"

void Parser::clearString(std::string& str) {
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

void Parser::parseData(std::string file, bool flag)
{
	std::vector<std::string> list;
	std::string str;
	std::ifstream fin(file, std::ios::in);
	while (getline(fin, str), str != ".code") {
		//getline(fin, str);
		if (str != ".data") {
			clearString(str);
			list.push_back(str);
		}
	}
	fin.close();

	for (auto i : list) {
		std::cout << i << "\n";
	}

}