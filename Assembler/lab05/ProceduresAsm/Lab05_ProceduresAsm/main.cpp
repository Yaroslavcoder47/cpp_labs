#include <iostream>

extern "C" bool __stdcall  Palindrome(char*, int);
extern "C" char* __stdcall DelSymbol(char*, int, char);
extern "C" int __fastcall CountNumbers(int, char*);
extern "C" char* __fastcall ChangeLetters(int, char*);


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

	//For second task
	/*std::cout << "Enter string:\n";
	char st[40];
	std::cin >> st;
	std::cout << "Max value of numbers: " << CountNumbers(std::strlen(st), st);	*/


	// For third task
	/*std::cout << "Enter string:\n";
	char st[40];
	std::cin >> st;
	std::cout << "Enter a symbol: ";
	char sym;
	std::cin >> sym;
	std::cout << DelSymbol(st, std::strlen(st), sym);*/

	//For forth task
	std::cout << "Enter string:\n";
	char st[40];
	std::cin.getline(st, 256); 
	std::cout << "New string\n";
	ChangeLetters(std::strlen(st), st);
	std::cout << st;

	return 0;
}