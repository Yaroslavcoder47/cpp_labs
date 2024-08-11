#include <iostream>
#include <set>
#include "libraryVector.h"
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

using std::ofstream;
using std::ifstream;
using std::string;
using std::vector;
using std::pair;

vector<pair<string, string>> readVector(string filePath) 
{
	ifstream fin(filePath, std::ios::in);
	size_t size;
	fin >> size;
	vector<pair<string, string>> container(size);
	
	for (size_t i = 0; i < size; ++i) {
		fin >> container[i].first;
		fin.ignore();
		fin >> container[i].second;
	}
	fin.close();
	return container;
}


void checkSubstring(string filePath, vector<pair<string, string >> container)
{
	ofstream fout(filePath, std::ios::app);
	for (size_t i = 0; i < container.size(); ++i) {
		if (container[i].first.find(container[i].second) != string::npos) {
			fout << "YES\n";
			size_t iter = container[i].first.find(container[i].second);
			fout << "On position: " << iter << '\n';
		}
		else {
			fout << "NO\n";
			fout << "On position: " << -1 << '\n';
		}
	}
}