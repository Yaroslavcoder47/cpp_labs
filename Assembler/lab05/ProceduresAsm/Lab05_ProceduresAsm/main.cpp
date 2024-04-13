#include <iostream>

extern "C" bool __stdcall  Palindrome(char*, int);

int main()
{	
	std::cout << "Enter string:\n";
	char st[40];
	std::cin >> st;
	if (Palindrome(st, std::strlen(st))) {
		std::cout << "'" << st << "' is a palindrome";
	}
	else {
		std::cout << "'" << st << "' is not a palindrome";
	}
	return 0;
}