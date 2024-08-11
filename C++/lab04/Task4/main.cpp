/**
* Дано два возрастающих массива. Найти количество общих элементов в них.
*/

// Test cases
//
//	size1	size2		firstArray			secondArray			count
//	4		4			1 2 5 4				5 3 4 9				2
//	5		4			5 6 1 9 7			7 7 2 9				2
//	3		3			1 4 5				5 4 1				3
//	6		5			4 4 4 4 4 4			1 2 3 4 5			1
//	4		3			8 4 1 0				2 3 6				0			

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

int findCommonElements(vector<int>& v1, vector<int>& v2);

int main()
{
	cout << "Enter size of first array: ";
	int size1;
	cin >> size1;
	vector<int> firstArray(size1);
	cout << "Input elements of first array: \n";
	for (int i = 0; i < size1; ++i) {
		cin >> firstArray[i];
	}
	cout << "Enter size of second array: ";
	int size2;
	cin >> size2;
	vector<int> secondArray(size2);
	cout << "Input elements of second array: \n";
	for (int i = 0; i < size2; ++i) {
		cin >> secondArray[i];
	}

	int countOfCommonElements = findCommonElements(firstArray, secondArray);
	
	cout << "Count of common elements in two arrays: " << countOfCommonElements;
	return 0;
}

int findCommonElements(vector<int>& v1, vector<int>& v2)
{
	int count = 0;
	for (int i = 0; i < v1.size(); ++i) {
		for (int j = 0; j < v2.size(); ++j) {
			if (v1[i] == v2[j]) {
				count++;
				v1.erase(v1.begin() + i);
				i--;
				v2.erase(v2.begin() + j);
				j--;
				break;
			}
		}
	}
	return count;
}