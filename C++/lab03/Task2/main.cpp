/**
* Ваша задача — для заданного числа n проверить, обращается ли в единицу
последовательность, начинающаяся с числа n. Обратите внимание, что если ответ
«нет», то программа должна выдать такой ответ, а не зациклиться. Можно считать, что
достаточно проверить 100 000 первых шагов.
*/

#include <iostream>

using std::cin;
using std::cout;

int main() {
	cout << "Enter number n: ";
	int n;
	cin >> n;
	int tmp = n;

	int i = 0;
	while (tmp != 1 && i <= 100000) {
		if (!(tmp % 2)) {
			tmp /= 2;
		}
		else {
			tmp = tmp * 3 + 1;
		}
		i++;
	}
	if (i > 100000) {
		cout << "Number " << n << " does not turn to 1.";
	}
	else {
		cout << "Number " << n << " turns to 1 for " << i << " steps.";
	}
	return 0;
}