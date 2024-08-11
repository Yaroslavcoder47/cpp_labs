/**
* Для заданного n найдите количество целых неотрицательных пар x и y таких, что
*x^2 + y^2 < n^2,
*пользуясь только операциями с целыми числами. Вы получите дополнительные баллы,
*если ваше решение совершает линейное от n количество операций. То есть существует
*такая константа C, что количество операций не превосходит Cn для любого n.
*/

#include <iostream>

using std::cin;
using std::cout;

int main() {
    cout << "Enter value of n: ";
    int n;
    cin >> n;
    long long ans = 0;
    
    for (int x = 0; x <= n; ++x) {
        int y = (int)(sqrt(n * n - x * x));

        y -= ( fabs((float)(int)sqrt(n * n - x * x) - sqrt(n * n - x * x)) < 0.000001 ) ? 1 : 0;
        if (x > y) {
            break;
        }
        ans += (y - x + 1);
    }
    cout << ans;
	return 0;
}