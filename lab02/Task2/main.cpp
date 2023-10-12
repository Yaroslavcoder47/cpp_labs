/*Даны координаты двух различных полей шахматной доски x1, y1, x2, y2 (целые числа, 
лежащие в диапазоне 1–8). Проверить истинность высказывания: «Ладья за один ход может 
перейти с одного поля на другое»*/

#include <iostream>
#include <string>

using std::cin;	
using std::cout;
using std::string;

int main() {
	cout << "Enter coordinates x, y of first field: \n";
	int x1, y1;
	cout << "x1 = ";
	cin >> x1;
	cout << "y1 = ";
	cin >> y1;
	cout << "Enter coordinates x, y of second field: \n";
	int x2, y2;
	cout << "x2 = ";
	cin >> x2;
	cout << "y2 = ";
	cin >> y2;
	string verdict;

	if (x1 == x2 || y1 == y2) {
		verdict = "Can move";
	}
	else {
		verdict = "Can't move";
	}

	cout << verdict;
	return 0;
}