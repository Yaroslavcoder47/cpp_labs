/**
* ���� N �����, ������ ����������� ��� � a[i] ������ . �� ������� 0 ����������� ��� 
* ������ (�� ���� ������ ����� � 0, a[1], 2*a[1] ...). ������� K ������ ����������. ���� ��� 
* ������ � ���� � �� �� ������� �����������, �� ������ ������� � ������� �������. 
* (std:pair<int, int>) 
*/

#include <iostream>
#include <vector>
#include "library.h"

using std::vector;
using std::pair;

int main()
{
	vector<int> container;
	int n; // number of elements
	int k; // number of executions
	inputData(container, n, k);
	solution(container, k);
	return 0;
}