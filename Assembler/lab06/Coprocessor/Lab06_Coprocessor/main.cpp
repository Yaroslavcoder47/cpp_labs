#include <iostream>
#include <cmath>

extern "C" float __fastcall calcExpression(float, float);

float cFuncTask1(float x, float y) {
	return (fabs(x - y) * cosf((x / y) + (y / x)));
}

int main()
{
	float* xPtr;
	float* yPtr;
	float x, y;
	float resultAsm;
	float resultC;
	std::cout << "Input variables:\n";
	std::cout << "x = ";
	std::cin >> x;
	std::cout << "y = ";
	std::cin >> y;
	xPtr = &x;
	yPtr = &y;
	__asm {
		mov ecx, dword ptr [xPtr]
		mov edx, dword ptr [yPtr]
		call calcExpression
		fstp dword ptr[resultAsm]
	}
	resultC = cFuncTask1(x, y);
	std::cout << "Asembler result: " << resultAsm << '\n';
	std::cout << "C++ function result: " << resultC;
	return 0;
}