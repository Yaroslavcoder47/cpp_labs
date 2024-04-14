#include <iostream>
#include <cmath>

float cFuncTask1(float x, float y) {
	return (fabs(x - y) * cosf((x / y) + (y / x)));
}

int main()
{
	float x, y;
	float resultAsm;
	float resultC;
	std::cout << "Input variables:\n";
	std::cout << "x = ";
	std::cin >> x;
	std::cout << "y = ";
	std::cin >> y;

	__asm {
		finit
		fld x
		fld y
		fsubp st(1), st(0)
		fabs
		fld x
		fld y
		fdivp st(1), st(0)
		fld y
		fld x
		fdivp st(1), st(0)
		fadd
		fcos
		fmul
		fstp dword ptr[resultAsm]
	}
	resultC = cFuncTask1(x, y);
	std::cout << "Asembler result: " << resultAsm << '\n';
	std::cout << "C++ function result: " << resultC;
	return 0;
}