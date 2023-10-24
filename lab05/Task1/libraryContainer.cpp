#include <iostream>
#include <set>
#include "libraryContainer.h"
#include <string>
#include <fstream>
#include <algorithm>

using std::ofstream;
using std::ifstream;
using std::string;
using std::multiset;

multiset<string> readMultiset(string filePath) {
	string str;
	ifstream fin(filePath, std::ios::in);
	multiset<string> container;
	while (getline(fin, str)) {
		container.insert(str);
	}
	fin.close();
	return container;
}

void printMultiset(string operation, string filePath, multiset<string> container)
{
	ofstream output(filePath, std::ios::app);
	output << operation << '\n';
	for (const auto& tmp : container) {
		output << tmp << '\n';
	}
	output.close();
}

multiset<string> multisetUnion(multiset<string> setA, multiset<string> setB)
{
	multiset<string> setC;
	set_union(setA.begin(), setA.end(), setB.begin(), setB.end(), inserter(setC, setC.begin()));
	return setC;
}

multiset<string> multisetIntersection(multiset<string> setA, multiset<string> setB)
{
	multiset<string> setC;
	set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(), inserter(setC, setC.begin()));
	return setC;
}

std::multiset<std::string> multisetDifference(std::multiset<std::string> setA, std::multiset<std::string> setB)
{
	multiset<string> setC;
	set_difference(setA.begin(), setA.end(), setB.begin(), setB.end(), inserter(setC, setC.begin()));
	return setC;
}