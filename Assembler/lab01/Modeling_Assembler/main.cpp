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


int main()
{
	map<string, int> dataNumber;
	map<string, string> dataResult;
	Parser p;
	dataNumber = p.parseData("input.txt", 1);
	dataResult = p.parseCode("input.txt");
	for (const auto& i : dataNumber) {
		cout << i.first << " " << i.second << "\n";
	}
	for (const auto& i : dataResult) {
		cout << i.first << " " << i.second << "\n";
	}
	return 0;
}