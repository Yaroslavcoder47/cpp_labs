/*Дано вещественное число а. Пользуясь только операцией умножения, 
получить (импользуйте удобное именование переменных, например a3 для a
в кубе, a8 для a в 8-й степени):*/

#include <iostream>

using std::cin;
using std::cout;

int main() {
	cout << "Input value of a: ";
	long double a;
	cin >> a;
	/*Пункт а*/
	
	long double a2;
	long double a4;
	a2 = a * a;
	a4 = a2 * a2;
	cout << "Value of a^4 = " << a4 << '\n';
	

	/*Пункт б*/
	/*
	long double a2;
	long double a6;
	a2 = a * a;
	a6 = a2 * a2 * a2;
	cout << "Value of a^6 = " << a6 << '\n';
	*/

	/*Пункт в*/
	/*
	long double a2;
	long double a7;
	a2 = a * a;
	a7 = a2 * a2 * a2 * a;
	cout << "Value of a^7 = " << a7 << '\n';
	*/

	/*Пункт г*/
	/*
	long double a2;
	long double a8;
	long double a4;
	a2 = a * a;
	a4 = a2 * a2;
	a8 = a4 * a4;
	cout << "Value of a^8 = " << a8 << '\n';
	*/

	/*Пункт д*/
	/*
	long double a2;
	long double a4;
	long double a9;
	a2 = a * a;
	a4 = a2 * a2;
	a9 = a4 * a4 * a;
	cout << "Value of a^9 = " << a9 << '\n';
	*/

	/*Пункт е*/
	/*
	long double a2;
	long double a4;
	long double a10;
	a2 = a * a;
	a4 = a2 * a2;
	a10 = a4 * a4 * a2;
	cout << "Value of a^10 = " << a10 << '\n';
	*/
	
	/*Пункт ж*/
	/*
	long double a2;
	long double a4;
	long double a13;
	a2 = a * a;
	a4 = a2 * a2;
	a13 = a4 * a4 * a4 * a;
	cout << "Value of a^13 = " << a13 << '\n';
	*/

	/*Пункт з*/
	/*
	long double a2;
	long double a5;
	long double a15;
	a2 = a * a;
	a5 = a2 * a2 * a;
	a15 = a5 * a5 * a5;
	cout << "Value of a^15 = " << a15 << '\n';
	*/

	/*Пункт и*/
	/*
	long double a2;
	long double a4;
	long double a8;
	long double a21;
	a2 = a * a;
	a4 = a2 * a2;
	a8 = a4 * a4;
	a21 = a8 * a8 * a4 * a;
	cout << "Value of a^21 = " << a21 << '\n';
	*/

	/*Пункт к*/
	/*
	long double a2;
	long double a4;
	long double a8;
	long double a28;
	a2 = a * a;
	a4 = a2 * a2;
	a8 = a4 * a4;
	a28 = a8 * a8 * a8 * a4;
	cout << "Value of a^28 = " << a28 << '\n';
	*/

	/*Пункт л*/
	/*
	long double a2;
	long double a4;
	long double a8;
	long double a16;
	long double a32;
	long double a64;
	a2 = a * a;
	a4 = a2 * a2;
	a8 = a4 * a4;
	a16 = a8 * a8;
	a32 = a16 * a16;
	a64 = a32 * a32;
	cout << "Value of a^64 = " << a64 << '\n';
	*/
}