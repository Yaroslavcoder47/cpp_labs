/**
* ���o 2 �����, ���� � ��������� ������� (�����, M ����), ������ ���� � N 
* ��������� (������ ������ � ��������� ������): add number (��������, add 7) - �������� 
* �����, delete number - ������� �����, find_min - ������� �������, is_exist number -
* ��������� �������������� ���������. ��������� �������� ������ � ��������� � 
* ��������� ��� ���������� ��� ������� �� ������� �����. ��������� ���������� 
* �������� � �������� ����. (std::multiset) 
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