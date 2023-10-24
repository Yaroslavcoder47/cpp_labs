/**
* ƒан вектор пар строк. ƒл€ каждого элемента вектора вывести YES или NO если
* втора€ строка €вл€етс€ подстрокой первой и позицию первого вхождени€ (или -1, если NO).
*/

// Test cases
//
//	First string		Second  string		Verdict		Position
// 
//	Grusha				horsha				NO			-1
//	frfrfapple			apple				YES			5
//	goblim				bli					YES			2
//	brughko				ghkoi				NO			-1

#include <iostream>
#include <fstream>
#include <string>
#include "libraryVector.h"
#include <map>
#include <vector>

using std::ifstream;
using std::ofstream;
using std::string;
using std::map;
using std::pair;
using std::vector;

int main()
{
	vector<pair<string, string>> container;

	container = readVector("data/input.txt");
	checkSubstring("data/output.txt", container);
	return 0;
}