#include <iostream>
extern "C" int __fastcall mul2(int);
int main() {

	std::cout << "multipled by 2 = " << mul2(10) << std::endl;

}