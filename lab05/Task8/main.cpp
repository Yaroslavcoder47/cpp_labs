/**
* ���� N �����. N - 1 ��� ������ ��������� - ����� ��� ����������� �����, 
* ���������� �� �� ������� � ��������� �� �����. �� ������ ���� ��������� �������� 
* ������� � �������� � �������.
*/

#include <iostream>
#include <vector>
#include "libraryVector.h"

using std::vector;
using namespace std;

int main()
{
	vector<size_t> container;

	container = readVector("data/input.txt", container);
	changeVector("data/output.txt", container);
	return 0;
}