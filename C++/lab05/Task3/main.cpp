/**
* Дан текстовый файл. Построить частотный словарь слов этого текста. Знаки 
* препинания в словах игнорировать (std::map).
*/

#include <iostream>
#include <fstream>
#include <string>
#include "librarySet.h"
#include <map>

using std::ifstream;
using std::ofstream;
using std::string;
using std::map;

int main()
{
	string text;
	text = readStrings("data/text.txt");
	
	changeString(text);

	map<string, size_t> container;
	createMap(text, container);
	printMap("data/output.txt", container);
	return 0;
}