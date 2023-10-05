/*В восточном календаре принят 60-летний цикл, состоящий из 12-летних подциклов, 
обозначаемых названиями цвета: зеленый, красный, желтый, белый и черный. В каждом 
подцикле годы носят названия животных: крысы, коровы, тигра, зайца, дракона, змеи, 
лошади, овцы, обезьяны, курицы, собаки и свиньи. По номеру года определить название
года по восточному календарю, если 2022 — годом черного тигра.*/

#include <iostream>
#include <cmath>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Enter a year: ";
	int year;
	cin >> year;
	string color;
	string animal;

	year -= 52;
	year %= 60;
	switch (year / 12){
	case 0:
		color = "green";
		break;
	case 1:
		color = "red";
		break;
	case 2:
		color = "yellow";
		break;
	case 3:
		color = "white";
		break;
	case 4:
		color = "black";
		break;
	default:
		break;
	}

	switch (year % 12){
	case 0:
		animal = "rat";
		break;
	case 1:
		animal = "cow";
		break;
	case 2:
		animal = "tiger";
		break;
	case 3:
		animal = "hare";
		break;
	case 4:
		animal = "dragon";
		break;
	case 5:
		animal = "snake";
		break;
	case 6:
		animal = "horse";
		break;
	case 7:
		animal = "sheep";
		break;
	case 8:
		animal = "monkey";
		break;
	case 9:
		animal = "chicken";
		break;
	case 10:
		animal = "dog";
		break;
	case 11:
		animal = "pig";
		break;
	default:
		break;
	}

	cout << "Year " << year << " is a year of: " << color << ' ' << animal;
	return 0;
}