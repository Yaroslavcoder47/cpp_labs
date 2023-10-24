#include <iostream>
#include <set>
#include "librarySet.h"
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using std::ofstream;
using std::ifstream;
using std::string;
using std::vector;

string readStrings(string filePath) {
	string str;
	string containerString;
	ifstream fin(filePath, std::ios::in);
	while (getline(fin, str)) {
		containerString += str + " ";
	}
	fin.close();
	return containerString;
}

void printMap(std::string filePath, std::map<std::string, size_t> container)
{
	ofstream output(filePath, std::ios::app);
	for (auto it : container) {
		output << it.first << " : " << it.second << '\n';
	}
}

string changeString(string& text)
{
	vector<char> punctuation{'.', ',', '!', '?'};
	for (size_t iter = 0; iter < text.size(); ++iter) {
		if(find(punctuation.begin(), punctuation.end(), text[iter]) != punctuation.end() && 
			(text[iter + 1] == ' ' || text[iter + 1] == '\0')) {
			text.erase(iter, 1);
			iter--;
		}
	}
	return text;
}

std::map<string, size_t> createMap(std::string str, std::map<string, size_t>& container)
{
	while (!str.empty()) {
		size_t index = str.find(' ');
		string word = str.substr(0, index);
		str.erase(0, index+1);
		container[word]++;
	}
	return container;
}