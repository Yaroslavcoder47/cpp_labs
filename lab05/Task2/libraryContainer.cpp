#include <iostream>
#include <set>
#include "libraryContainer.h"
#include <string>
#include <fstream>
#include <vector>

using std::ofstream;
using std::ifstream;
using std::string;
using std::set;
using std::vector;

vector<string> readStrings(string filePath) {
	string str;
	ifstream fin(filePath, std::ios::in);
	vector<string> container;
	while (getline(fin, str)) {
		container.push_back(str);
	}
	fin.close();
	return container;
}

void printNumberOfDifferentElements(string filePath, int number)
{
	ofstream output(filePath, std::ios::app);
	output << "Number of different elements in set: " << number;
	output.close();
}

int findDifferentElements(std::vector<string> container)
{
	set<string> setOfStrings;
	for (auto const& iter : container) {
		setOfStrings.insert(iter);
	}
	return setOfStrings.size();
}