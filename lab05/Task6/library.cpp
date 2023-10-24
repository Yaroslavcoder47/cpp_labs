#include <iostream>
#include <vector>
#include <algorithm>

using std::pair;
using std::cin;
using std::cout;
using std::vector;

void inputData(vector<int>& container, int& n, int& k)
{
	cout << "Input number of elements n: ";
	cin >> n;
	cout << "Input elements:\n";
	container.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> container[i];
	}
	cout << "Input number k: ";
	cin >> k;
}

void solution(vector<int>& container, int k)
{
	cout << "Number of tasks:\n";
	int time = 1;
	while (k != 0) {
		for (int i = 0; i < container.size(); ++i) {
			if (time % container[i] == 0) {
				cout << i + 1 << ' ';
				k--;
			}
			if (k == 0) {
				break;
			}
		}
		time++;
	}
}
