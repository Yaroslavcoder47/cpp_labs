/**
* ƒано N пар строк из маленьких латинских букв - название улицы и фамили€ 
* человека. Ќужно дл€ каждой улицы вывести сколько различных фамилий на ней живет. 
* ”лицы выводить в лексикографическом пор€дке (map<string, set<string>> или
* vector<pair<string, string>> и std::unique)
*/

#include <iostream>
#include <vector>
#include <string>
#include "library.h"

using std::vector;
using std::pair;
using std::string;


int main()
{
	vector<pair<string, string>> data;
	
	readData("data/input.txt", data);
	printData("data/output.txt", data);
	return 0;
}