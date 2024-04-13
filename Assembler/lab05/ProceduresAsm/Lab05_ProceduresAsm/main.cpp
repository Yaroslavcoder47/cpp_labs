#include <iostream>

extern "C" int __stdcall  Palindrome(char*, int);

int main()
{	
	int size;
	std::cout << "Enter size: ";
	std::cin >> size;
	std::cout << "Enter string:\n";
	char st[20];
	std::cin >> st;
	std::cout << Palindrome(st, size);
	return 0;
}