/**
* Рассмотрим следующую последовательность:
* a0 = 1
*ai+1 = 2ai ⊕ ai
*Где ⊕ — операция xor целых чисел.
*Сгенерируйте несколько первых чисел этой последовательности и выведите их в
*двоичной системе счисления, по одному в строке. Для наглядности можете вывести ‘ ’
*вместо ‘ 0 ’. Как называется полученная фигура? Ответ приведите в файле с решением.
*Попробуйте сгенерировать первые 60 строк этой фигуры. Получилось? А 120? Вместе с
*двоичным представлением выведите десятичное обычным оператором вывода.
*Объясните наблюдаемый эффект.
*Для получения дополнительных баллов выведите как можно больше корректных строк
*фигуры. Ещё больше баллов, если ваш код сможет вывести 1000 строк и не будет
*использовать массивы, строки или другие контейнеры.
*/

/**
* Фигура называется треугольник Серпинского
*/

#include <iostream>
#include <bitset>
#include <string>

using std::cin;
using std::cout;
using std::bitset;
using std::string;

int main() {
	cout << "Enter number n of strings of sequences: ";
	int n;
	cin >> n;
	size_t a0 = 1;
	size_t a;
	string numberInString;
	numberInString = bitset<64>{ a0 }.to_string();
	for (auto element : numberInString) {
		if (element == '0') {
			cout << ' ';
		}
		else{
			cout << element;
		}
	}
	cout << '\n';
	for (int i = 1; i < n; ++i) {
		a = (2 * a0) ^ a0;
		a0 = a;
		numberInString = bitset<64>{ a0 }.to_string();
		for (auto element : numberInString) {
			if (element == '0') {
				cout << ' ';
			}
			else {
				cout << element;
			}
		}
		cout << '\n';
	}

	a0 = 1;
	cout << a0 << '\n';
	for (int i = 1; i < n; ++i) {
		a = (2 * a0) ^ a0;
		a0 = a;
		cout << a << '\n';
	}
	return 0;
}