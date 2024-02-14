#include <iostream>

using std::cin;
using std::cout;

void FirstTask()
{
	int a, res;
	cout << "Input value of a: ";
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
		mov res, eax
	}
	cout << "The result of operation a^5+a^3+a: " << res << '\n';
}

void SecondTask()
{
	int a, res;
	cout << "Input value of a: ";
	cin >> a;
	__asm {
		mov eax, a
		mul eax
		mov ebx, eax
		sub ebx, 4
		imul ebx, 2
		mul eax
		imul eax, a
		add eax, ebx
		add eax, a
		mov ebx, a
		imul ebx, a
		imul ebx, a
		div ebx
		mov res, eax
	}

	cout << "The result of operation (a^5+2(a^2-4) + a)/a^3: " << res << '\n';
}

int main()
{
	//FirstTask();
	SecondTask();
	return 0;
}