/**
* Даны две матрицы размера n x k и k x m. Найти их произведение.
*/

//Test cases
//	n	k	m		firstMatrix				secondMtarix		resultMatrix
//	2	3	3		2 1 1					3 1					9 3
//					3 0 1					2 1					10 3
// 											1 0

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;

vector<vector<int>> multiplicationOfMatrices(vector<vector<int>>& v1, vector<vector<int>>& v2,
	vector<vector<int>>& resultArray, const int &n, const int& k, const int &m);

int main()
{
	cout << "Enter size n of first matrix: ";
	int n;
	cin >> n;
	cout << "Enter size k of first and second matrix: ";
	int k;
	cin >> k;
	cout << "Enter size m of second matrix: ";
	int m;
	cin >> m;
	vector<vector<int>> firstArray(n, vector<int>(k));
	vector<vector<int>> secondArray(k, vector<int>(m));
	vector<vector<int>> resultArray(n, vector<int>(m));
	cout << "Enter first matrix: \n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			cin >> firstArray[i][j];
		}
	}
	cout << "Enter second matrix: \n";
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> secondArray[i][j];
		}
	}

	multiplicationOfMatrices(firstArray, secondArray, resultArray, n, k, m);

	cout << "Result of multiplication: \n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << resultArray[i][j] << ' ';
		}
		cout << '\n';
	}
	return 0;
}

vector<vector<int>> multiplicationOfMatrices(vector<vector<int>>& v1, vector<vector<int>>& v2, 
	vector<vector<int>>& resultArray, const int& n, const int& k, const int& m)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int u = 0; u < k; u++) {
				resultArray[i][j] += v1[i][u] * v2[u][j];
			}
		}
	}
	return resultArray;
}
