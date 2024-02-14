#include <iostream>

using std::cin;
using std::cout;

int main()
{
	int a;
	cout << "Input your number: ";
	cin >> a;
	__asm {
		mov eax, a
		mul eax
		mov ebx, eax
		imul ebx, a
		mul eax
		imul eax, a
		add eax, ebx
		add eax, a
		mov a, eax
	}
	cout << "The result of operation a^5+a^3+a: " << a;
	return 0;
}