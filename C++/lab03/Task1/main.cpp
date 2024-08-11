/**
* 1.1
*���������� ����, ������� ��������� ����� n �������� ( n >= 0 ). ��� ���� ���������
*��������� � ������������ ����� ������ ����������, ����� n.

*1.2
* ���������� ���� for �� ������� unsigned int i , ������� ��������� �������� �� n-1 ��
*0 ������������. ��� ���� �������� �������� ������� ��������� ������ ������ ()
*����� for , � ����� ��������� ������������� break � continue .
*/

#include <iostream>

using std::cin;
using std::cout;

int main() {
	cout << "Enter number n: ";
	int n;
	cin >> n;
	int nTmp = n;

	/*Task 1.1*/
	while (n) {
		cout << n << ' ';
		n--;
	}

	cout << '\n';

	/*Task 1.2*/
	bool checkValueOfi = 1;
	for (unsigned int i = nTmp - 1; checkValueOfi; --i) {
		cout << i << ' ';
		if (!i) {
			checkValueOfi = 0;
		}
	}
	return 0;
}