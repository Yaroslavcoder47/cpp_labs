#include "Program.h"

int Program::main()
{
	RationalNumber<int> a(1, 2);
	RationalNumber<int> b(2, 3);
	RationalNumber<int> c;
	int e = 2;
	c = a / e;
	std::cout << c;
	return 0;
}
