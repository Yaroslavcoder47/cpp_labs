/*Дано вещественное число x. Не пользуясь никакими другими 
арифметическими действиями кроме сложения, вычитания и умножения 
вычислить выражения: 4x^3 + 3x^2 + 2x + 1 и -4x^3 + 3x^2 - 2x + 1.
Суммарно использовать не более 8 арифметических операций*/

#include <iostream>

using std::cin;
using std::cout;

int main() {
	// Пусть результат первого выражения 4x^3 + 3x^2 + 2x + 1 будет в переменной result1
	// Результат второго выражения -4x^3 + 3x^2 - 2x + 1 будет в переменной result2

	cout << "Input value of x: ";
	double x;
	cin >> x;
	double result1; // результат выражения 4x^3 + 3x^2 + 2x + 1
	double result2; // результат выражения -4x^3 + 3x^2 - 2x + 1
	double x2 = x * x;
	double a = 2 * x2 + 1; // выражение 2x^2 + 1
	double b = 2 * x * a; // выражение 4x^3 + 2x
	double c = a + x2; // выражение 3x^2 + 1
	result1 = b + c;
	result2 = c - b;
	cout << "Value of first expression: " << result1 << '\n';
	cout << "Value of second expression: " << result2 << '\n';

}