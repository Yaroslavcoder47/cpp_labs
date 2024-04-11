#include <iostream>

extern "C" float __fastcall CalculateSqrt(int, float*);

using std::cout;
using std::cin;

int main()
{
	int a = 3;
	float* b = new float(45.4);
	cout << *b;
}