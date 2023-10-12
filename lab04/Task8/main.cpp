/**
* Дано целое число k, а также k наборов ненулевых целых чисел. Признаком 
*завершения каждого набора является число 0 (оно в набор не входит). Для 
*каждого набора вывести количество его элементов. Вывести также общее 
*количество элементов во всех наборах.
*/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

void printVector(const int& k);

int main()
{
	cout << "Enter number k: ";
	int k;
	cin >> k;

	printVector(k);

	return 0;
}

void printVector(const int& k)
{
	vector<vector<int>> container(k, vector<int>());
	cout << "Enter the elements of the containers: \n";

	for (size_t i = 0; i != k; ++i) {
		for (size_t j = 0; ; ++j)
		{
			int element;
			cin >> element;

			if (element != 0) {
				container[i].push_back(element);
			}
			else {
				break;
			}
		}
	}
	int count = 0;
	cout << "Result: \n";

	for (int i = 0; i < container.size(); ++i) {
		cout << "Size of container: " << container[i].size() << '\n';
		count += container[i].size();
	}
	cout << '\n' << "There are " << count << " elements in all containers.";
}