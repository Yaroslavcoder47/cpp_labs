/**
* ѕоследовательностью ‘аре€. Ќапечатать в пор€дке возрастани€ все простые 
*несократимые дроби, заключенные между 0 и 1, знаменатели которых меньше 
*заданного числа n. 
*/

#include <iostream>

using std::cin;
using std::cout;

void findFareySequence(int n);

int main()
{
	cout << "Enter number n: ";
	int n;
	cin >> n;

	if (n == 0 || n == 1) {
		cout << "Invalid data.";
		return 0;
	}

    findFareySequence(n);
	return 0;
}

void findFareySequence(int n)
{
    int a = 0, b = 1, c = 1, d = n;
    int template_a, template_b;

    cout << "Farey Sequence is: \n";
    cout << a << '/' << b << '\n';
    while (c <= n) {
        int k = (n + b) / d;

        template_a = a;
        template_b = b;
        a = c;
        b = d;
        c = k * c - template_a;
        d = k * d - template_b;

        if (b != n) {
            cout << a << '/' << b << '\n';
        }
    }
}
