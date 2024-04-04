#include <iostream>
#include <vector>
#include "task1.h"
#include "task2.h"
#include "spdlog/spdlog.h"

//int main() {
//
//	spdlog::set_level(spdlog::level::trace);
//	spdlog::trace("program started.");
//
//	std::vector <int> vec = {4, 1, 1, 1, 1};
//	int* ptrArr = vec.data();
//
//	// Code on C++
//	/*int* length = ptrArr;
//	size_t i = 1;
//	while (i < *length) {
//		size_t j = *length;
//		while (j > i) {
//			if ((*(length + i)) == (*(length + j))) {
//				for (int k = j; k < *length; ++k) {
//					*(length + k) = *(length + k + 1);
//				}
//				*length = *length - 1;
//			}
//			--j;
//		}
//		++i;
//	}*/
//	
//	vectorRebuild(ptrArr);
//	std::cout << "Rebuild vector looks like:\n";
//
//	for (size_t i = 1; i <= vec[0]; ++i) {
//		std::cout << vec[i] << ' ';
//	}
//	std::cout << '\n';
//	std::cout << "Vector's size is " << vec[0] << '\n';
//
//	spdlog::trace("program finished.");
//	return 0;
//}

int main()
{
	std::cout << f();
}