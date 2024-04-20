#include <iostream>
#include <cmath>

extern "C" float __fastcall calcExpression(float, float);
extern "C" float __cdecl solveEquation();
extern "C" float __fastcall calcPi(int, int);
extern "C" float __fastcall calcLn(int);
extern "C" float __fastcall calcIntegral(int);
extern "C" float __fastcall powerFunc(int);

float cFuncTask1(float x, float y) {
	return (fabs(x - y) * cosf((x / y) + (y / x)));
}



int main()
{
	//For task1
	/*float* xPtr;
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
	std::cout << "C++ function result: " << resultC;*/

	//For task2
	/*float result;
	result = solveEquation();
	std::cout << result;*/

	
	//For task3
	/*int n;
	std::cin >> n;
	int* num = new int(8);
	float res;
	__asm {
		xor edx, edx
		mov ecx, n
		mov edx, dword ptr [num]
		call calcPi
		fstp dword ptr[res]	
	}
	std::cout << res;*/

	//For task4
	/*int n;
	std::cin >> n;
	float res;
	__asm {
		mov ecx, n
		call calcLn
		fstp dword ptr[res]
	}
	std::cout << res;*/

	//For task5
	/*int n;
	std::cin >> n;
	int* nptr = &n;
	float res;
	__asm {
		xor ecx, ecx
		mov ecx, dword ptr nptr
 		call calcIntegral
		fstp dword ptr[res]
	}
	std::cout << res;*/

	//For task6
	/*int n;
	std::cin >> n;
	float result;
	__asm {
		mov ecx, dword ptr[n]
		call powerFunc
		fstp dword ptr[result]
	}
	std::cout << result;*/
	return 0;
}