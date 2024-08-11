#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

using std::ofstream;
using std::ifstream;
using std::vector;
using std::string;


vector<size_t> readContainerOfData(string filePath)
{
	ifstream fin(filePath, std::ios::in);
	size_t size;
	fin >> size;
	vector<size_t> container(size);
	for (size_t i = 0; i < size; ++i) {
		fin >> container[i];
	}
	return container;
}

vector<string> readContainerOfCommands(string filePath)
{
	ifstream fin(filePath, std::ios::in);
	size_t size;
	fin >> size;
	fin.ignore();
	vector<string> container(size);
	for (size_t i = 0; i < size; ++i) {
		getline(fin, container[i]);
	}
	return container;
}

void makeOperations(string filePath, vector<size_t>& containerOfData, vector<string>& containerOfCommands)
{
	ofstream fout(filePath, std::ios::app);
	for (auto iter : containerOfCommands) {
		if (iter == "find_min") {
			size_t min = *std::min_element(containerOfData.begin(), containerOfData.end());
			fout << "Min_Element: " << min << '\n';
		}
		else {
			size_t pos = iter.find(' ');
			string str = iter.substr(0, pos);
			string numberString = iter.substr(pos + 1, iter.size());
			size_t number = stoi(numberString);
			if (str == "add") {
				containerOfData.push_back(number);
				fout << "New array: \n";
				for (size_t i = 0; i < containerOfData.size(); ++i) {
					fout << containerOfData[i] << ' ';
				}
				fout << '\n';
			}
			if (str == "delete") {
				auto it = remove(containerOfData.begin(), containerOfData.end(), number);
				containerOfData.erase(it, containerOfData.end());
				fout << "New array: \n";
				for (size_t i = 0; i < containerOfData.size(); ++i) {
					fout << containerOfData[i] << ' ';
				}
				fout << '\n';
			}
			if (str == "is_exist") {
				if (find(containerOfData.begin(), containerOfData.end(), number) != containerOfData.end()) {
					fout << "Element " << number << " is exist.\n";
				}
				else {
					fout << "Element " << number << " is not exist.\n";
				}
			}
		}
	}
}