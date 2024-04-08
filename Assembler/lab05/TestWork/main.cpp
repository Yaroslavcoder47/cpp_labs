#include <iostream>
extern "C" int __fastcall mul2fastCall(int);
extern "C" int __stdcall mul2StdCall(int);
int main() {

	std::cout << "multipled by 2 = " << mul2(10) << std::endl;

}

