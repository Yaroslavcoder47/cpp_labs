/*Выполните все арифметические операции
(https://en.cppreference.com/w/cpp/language/expressions ) с двумя целыми
числами x и y.*/
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
    cout << "Unary plus: " << '\n';
    cout << "for x: " << +x << ',' << " for y: " << +y << '\n';
    cout << "Unary minus: " << '\n';
    cout << "for x: " << -x << ',' << " for y: " << -y << '\n';
    cout << "Addition: x + y = " << x + y << '\n';
    cout << "Subtraction: x - y = " << x - y << '\n';
    cout << "Multiplication: x * y = " << x * y << '\n';
    cout << "Division: x / y = " << x / y << '\n';
    cout << "Remainder: x % y = " << x % y << '\n';
    cout << "Bitwise NOT: " << '\n';
    cout << "for x: " << ~x << ',' << " for y: " << ~y << '\n';
    cout << "Bitwise AND: " << (x & y) << '\n';
    cout << "Bitwise OR: " << (x | y) << '\n';
    cout << "Bitwise XOR: " << (x ^ y) << '\n';
    cout << "Bitwise left shift: " << (x << y) << '\n';
    cout << "Bitwise right shift: " << (x >> y) << '\n';
    return 0;
}
