#include <iostream>

using std::cin;
using std::cout;
using namespace std;

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

void ThirdTask()
{
	int a, n;
	cout << "Input value of a: ";
	cin >> a;
	__asm {
		mov ecx, 1
		mov eax, a
		jo end_
		begin_:
			imul a
			jo end_
			add ecx, 1
			jmp begin_
		end_:
			mov n, ecx
	}
	cout << n;
}

void FourthTask()
{
	_int16 a1, a2, a3;
	_int16 b1, b2, b3;
	_int16 c1, c2, c3;
	/*cout << "Input a1, a2, a3: \n";
	cin >> a1 >> a2 >> a3;
	cout << "Input b1, b2, b3: \n";
	cin >> b1 >> b2 >> b3;*/
	a1 = 0x1234;
	a2 = 0x5678;
	a3 = 0x9ABC;

	b1 = 0xDEF0;
	b2 = 0x1234;
	b3 = 0x5678;
	__asm {
		mov ax, a1
		add ax, b1
		mov c1, ax

		mov ax, a2
		adc ax, b2
		mov c2, ax

		mov ax, a3
		adc ax, b3
		mov c3, ax
		
	}
	long long result = (static_cast<long long>(c3) << 32) | (static_cast<long long>(c2) << 16) | c1;
	cout << "Result in decimal: " << dec << result << endl;
}

int main()
{
	//FirstTask();
	//SecondTask();
	//ThirdTask();
	FourthTask();
	return 0;
}
