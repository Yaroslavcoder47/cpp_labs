/**
* Данo 2 файла, один с исходными данными (числа, M штук), второй файл с N 
* запросами (каждый запрос в отдельной строке): add number (например, add 7) - добавить 
* число, delete number - удалить число, find_min - вывести минимум, is_exist number -
* проверить принадлежность коллекции. Загрузить исходные данные в коллекцию и 
* выполнить над элементами все запросы из второго файла. Результат выполнения 
* записать в выходной файл. (std::multiset) 
*/

#include <iostream>
#include <fstream>
#include <vector>
#include "libraryCollections.h"
#include <string>

using std::vector;
using std::string;

int main()
{
	vector<size_t> containerOfData;
	vector<string> containerOfCommands;

	containerOfData = readContainerOfData("data/information.txt");
	containerOfCommands = readContainerOfCommands("data/requests.txt");

	makeOperations("data/output.txt", containerOfData, containerOfCommands);
	return 0;
}