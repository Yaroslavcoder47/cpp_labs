/**
* Переставить элементы массива в обратном порядке без дополнительных массивов
*/

//Test cases
//		n		vector		new vector
//		3		1 5 4		4 5 1
//		4		4 7 5 2		2 5 7 4
//		1		5			5

#include <iostream>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::vector;
using std::swap;

vector<int> changeArray(vector<int>& elements);

int main()
{
	cout << "Enter number of elements: ";
	int n;
	cin >> n;
	vector<int> elements(n);
	cout << "Eneter elements of array: \n";
	for (int i = 0; i < n; ++i) {
		cin >> elements[i];
	}

	changeArray(elements);

	for (int i = 0; i < n; ++i) {
		cout << elements[i] << ' ';
	}
	return 0;
}

vector<int> changeArray(vector<int>& elements)
{
	for (int i = 0; i < elements.size() / 2; ++i) {
		swap(elements[i], elements[elements.size() - 1 - i]);
	}
	return elements;
}