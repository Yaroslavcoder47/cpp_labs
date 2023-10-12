/**
* ƒан массив из n целых чисел. ѕроверить, €вл€етс€ ли он перестановкой, то есть 
содержит различные числа от 1 до n.
*/

// Test cases :
//
//size		items						result
// 6		1 2 3 4 5 6					It is a permutation
// 6		3 8 0 6 8 0					It is not a permutation
// 3		2 1	3						It is a permutation
// 10		5 7 9 10 6 8 3 4 1 2		It is a permutation
// 4		1 2 3 5						It is not a permutation


#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using std::cin;
using std::cout;
using std::vector;
using std::swap;

bool checkArray(vector<int>& elements, vector<int>& secondArray);

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

	vector<int> secondArray;
	for (int i = 0; i < n; ++i) {
		secondArray.push_back(i + 1);
	}

	sort(elements.begin(), elements.end());

	if (checkArray(elements, secondArray)) {
		cout << "It is a permutation";
	}
	else {
		cout << "It is not a permutation";
	}
	return 0;
}

bool checkArray(vector<int>& elements, vector<int>& secondArray)
{
	for (int i = 0; i < elements.size(); ++i) {
		if (elements[i] != secondArray[i]) {
			return false;
		}
	}
	return true;
}