/**
* Дано число n. Найти наименьшую цифру, которая отсутствует в его десятичной 
*записи. Подумайте, над возможностью использования контейнеров std::map, 
*std::set.
*/

//Test cases
//	n						verdict
// 
//	41201						3
//	10							2			
//	102334566789475				All digits are in number
//	1023456789					All digits are in number
//	45601239					7						

#include <iostream>
#include <set>
#include <algorithm>

using std::cin;
using std::cout;
using std::set;

// structure set includes all digits
set<int> digits = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

int findMinDigit(size_t n);

int main()
{
	cout << "Enter number n: ";
	size_t n;
	cin >> n;
	size_t verdict = findMinDigit(n);

	if (verdict == -1) {
		cout << "All digits are in number.";
		return 0;
	}
	cout << "Min digit which is not in " << n << " is: " << verdict;
	return 0;
}

// we take a digit if number n and then check it in structure set (delete this digit in the set)
int findMinDigit(size_t n)
{
	int minDigit;
	int digit;
	while (n) {
		digit = n % 10;
		digits.erase(digit);
		if (digits.empty()) {
			return -1;
		}
		n /= 10;
	}
	minDigit = *digits.begin();
	return minDigit;
}