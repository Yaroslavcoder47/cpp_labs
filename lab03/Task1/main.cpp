/**
* 1.1
*Реализуйте цикл, который совершает ровно n итераций ( n >= 0 ). При этом запрещено
*создавать и использовать любые другие переменные, кроме n.

*1.2
* Реализуйте цикл for по индексу unsigned int i , который пробегает значения от n-1 до
*0 включительно. При этом изменять значение индекса разрешено только внутри ()
*цикла for , а также запрещено использование break и continue .
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