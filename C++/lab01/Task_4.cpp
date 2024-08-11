/*Для данных целых чисел x и y вычислите выражение (задание 4)*/
#include <iostream>
#include <cmath>

using std::cin;
using std::cout;

int main() {
	cout << "Input value of x: ";
	double x;
	cin >> x;
	cout << "Input value of y: ";
	double y;
	cin >> y;
	double result = ((3 + x * x - pow(y, 3)) * (x + 3) * (x + 3)) / (x - y * y);
	cout << "Result: " << result << '\n';
}