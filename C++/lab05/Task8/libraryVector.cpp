#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include "libraryVector.h"

using std::vector;
using std::ofstream;
using std::ifstream;
using std::string;


vector<size_t> readVector(string filePath, vector<size_t>& container)
{
	ifstream fin(filePath, std::ios::in);
	size_t n;
	fin >> n;
	container.resize(n);
	for (size_t i = 0; i < n; ++i) {
		fin >> container[i];
	}
	return container;
	
}

void changeVector(string filePath, vector<size_t>& container)
{
	ofstream fout(filePath, std::ios::app);
	while (container.size() != 1) {
		auto firstMin = std::min_element(container.begin(), container.end());
		size_t summa = *firstMin;
		container.erase(firstMin);
		auto secondMin = std::min_element(container.begin(), container.end());
		summa += *secondMin;
		container.erase(secondMin);
		container.push_back(summa);

		fout << "New vector:\n";
		for (auto const iter : container) {
			fout << iter << ' ';
		}
		fout << '\n';	
	}
}