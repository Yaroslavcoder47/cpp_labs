/**
* Дан массив из n + m элементов. Без использования вспомогательных массивов 
* поменять в нём местами начало длины n и конец длины m.
*/

// Test cases
//
// n	m		array				new array
// 2	4		1 2 3 4 5 6			3 4 5 6 1 2
// 3	1		1 2 3				3 1 2
// 2	0		1 2					1 2


#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

vector<int> changeArray(vector<int>& container, int n);

int main()
{
	cout << "Enter number n for size of array: ";
	int n;
	cin >> n;
	cout << "Enter number m for size of array: ";
	int m;
	cin >> m;
	vector<int> container(n + m);
	cout << "Enter elements of array: \n";
	for (int i = 0; i < container.size(); ++i) {
		cin >> container[i];
	}

	changeArray(container, n);

	cout << "New array: \n";
	for (int i = 0; i < container.size(); ++i) {
		cout << container[i] << ' ';
	}
	return 0;
}

vector<int> changeArray(vector<int>& container, int n)
{
	for (int i = 0; i < n; ++i) {
		container.push_back(*container.begin());
		container.erase(container.begin());
	}
	return container;
}