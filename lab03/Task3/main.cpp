/**
* Вводится номер кредитной карты (16-значное число). Проверьте, является ли он
*корректным.
*/

#include <iostream>

using std::cin;
using std::cout;

int main() {
	cout << "Enter number of credit card: \n";
	size_t number;
	cin >> number;
	int summOfMultDigits = 0;
	int summOfOtherDigits = 0;
	size_t tmp = number;

	int i = 0;
	while (tmp) {
		if (i % 2) {
			int digit = tmp % 10;
			if (digit * 2 > 9) {
				summOfMultDigits += (digit * 2) % 10 + ((digit * 2) / 10);
			}
			else {
				summOfMultDigits += digit * 2;
			}
			
		}
		else {
			summOfOtherDigits += tmp % 10;
		}
		i++;
		tmp /= 10;
	}
	int summOfAllDigits = summOfMultDigits + summOfOtherDigits;

	if (!(summOfAllDigits % 10)) {
		cout << "Number of credit card " << number << " is correct.";
	}
	else {
		cout << "Number of credit card " << number << " is incorrect.";
	}
	return 0;
}