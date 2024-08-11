/*Ќаписать программу, котора€ определ€ет дату предыдущего дн€.
Ќапример: 
¬ведите цифрами сегодн€шнюю дату (число мес€ц год) Ц> 1 9 2022
¬чера 31.08.2022*/

#include <iostream>

using std::cin;
using std::cout;

int main() {
	cout << "Enter todays date in formar D M Y: \n";
	int day, month, year;
	cin >> day;
	cin >> month;
	cin >> year;
	int previousDay = day - 1;
	int previousMonth = month;
	int previousYear = year;

	if (day == 1) {
		previousMonth = month - 1;
		switch (month)
		{
		case 1: 
			previousYear = year - 1;
			previousMonth = 12;
			previousDay = 31;
			break;
		case 2:
			previousDay = 31;
			break;
		case 3:
			if (year % 4 == 0) {
				previousDay = 29;
			}
			else {
				previousDay = 28;
			}
			break;
		case 4:
			previousDay = 31;
			break;
		case 5:
			previousDay = 30;
			break;
		case 6:
			previousDay = 31;
			break;
		case 7:
			previousDay = 30;
			break;
		case 8:
			previousDay = 31;
			break;
		case 9:
			previousDay = 31;
			break;
		case 10:
			previousDay = 30;
			break;
		case 11:
			previousDay = 31;
			break;
		case 12:
			previousDay = 30;
			break;
		default:
			break;
		}
	}

	cout << "Previous date: " << previousDay << '.' << previousMonth << '.' << previousYear;
	return 0;

}