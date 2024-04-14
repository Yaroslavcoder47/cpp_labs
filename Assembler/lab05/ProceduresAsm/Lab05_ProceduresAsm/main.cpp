#include <iostream>

extern "C" bool __stdcall  Palindrome(char*, int);
extern "C" char* __stdcall DelSymbol(char*, int, char);

int main()
{	
	// For first task
	/*std::cout << "Enter string:\n";
	char st[40];
	std::cin >> st;
	if (Palindrome(st, std::strlen(st))) {
		std::cout << "'" << st << "' is a palindrome";
	}
	else {
		std::cout << "'" << st << "' is not a palindrome";
	}*/


	// For third task
	std::cout << "Enter string:\n";
	char st[40];
	std::cin >> st;
	std::cout << "Enter a symbol: ";
	char sym;
	std::cin >> sym;
	char* newSt = DelSymbol(st, std::strlen(st), sym);
	
	for (size_t i = 0; i < size; ++i) {
		std::cout << newSt[i] << ' ';
	}
	return 0;
}