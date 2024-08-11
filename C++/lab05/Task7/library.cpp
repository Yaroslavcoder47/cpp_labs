#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include "library.h"

using std::vector;
using std::pair;
using std::string;
using std::ifstream;
using std::ofstream;
using std::sort;

void readData(string filePath, vector<pair<string, string>>& data)
{
	ifstream fin(filePath, std::ios::in);
	int size;
	fin >> size;
	data.resize(size);
	for (int i = 0; i < size; ++i) {
		fin >> data[i].first;
		fin >> data[i].second;
	}
	sort(data.begin(), data.end());
}

void printData(std::string filePath, std::vector<std::pair<std::string, std::string>>& data)
{
	ofstream fout(filePath, std::ios::app);
	for (int i = 0; i < data.size(); ++i) {
		if (i == 0 || data[i].first != data[i - 1].first) {
			fout << data[i].first << ":\n";
			for (int j = i; j < data.size(); ++j) {
				if (data[j].first == data[i].first) {
					fout << data[j].second << '\n';
				}
			}
			fout << '\n';
		}
	}
}