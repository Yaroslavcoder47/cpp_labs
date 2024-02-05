
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
	map<string, int> m;
	Parser p;
	m = p.parseData("input.txt", 1);
	for (const auto& i : m) {
		cout << i.first << " " << i.second << "\n";
	}
	return 0;
}