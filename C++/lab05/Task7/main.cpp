/**
* ���� N ��� ����� �� ��������� ��������� ���� - �������� ����� � ������� 
* ��������. ����� ��� ������ ����� ������� ������� ��������� ������� �� ��� �����. 
* ����� �������� � ������������������ ������� (map<string, set<string>> ���
* vector<pair<string, string>> � std::unique)
*/

#include <iostream>
#include <vector>
#include <string>
#include "library.h"

using std::vector;
using std::pair;
using std::string;


int main()
{
	vector<pair<string, string>> data;
	
	readData("data/input.txt", data);
	printData("data/output.txt", data);
	return 0;
}