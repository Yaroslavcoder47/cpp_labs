﻿/*Поменяйте местами значения переменных x и y тремя способами: 1) через 
дополнительную переменную, 2) используя операции +, -, 3) используя 
оператор xor.*/
#include <iostream>

using std::cin;
using std::cout;

int main() {
	cout << "Input value of x: ";
	int x;
	cin >> x;
	cout << "Input value of y: ";
	int y;
	cin >> y;
	/*Первый способ через доп. переменную*/
	/*
	int z;
	z = x;
	x = y;
	y = z;
	cout << "x = " << x << "; y = " << y << '\n';
	*/

	/*Второй способ, используя операции +, -*/
	/*
	x = x + y;
	y = x - y;
	x = x - y;
	cout << "x = " << x << "; y = " << y << '\n';
	*/

	/*Третий способ, используя оператор xor*/
	x ^= y ^= x ^= y;
	cout << "x = " << x << "; y = " << y << '\n';
}