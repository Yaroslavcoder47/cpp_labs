#include <iostream>
#include <vector>
#include "task1.h"
#include "task2.h"
#include "spdlog/spdlog.h"
//
//int main() {
//
//	spdlog::set_level(spdlog::level::trace);
//	spdlog::trace("program started.");
//
//	std::vector <int> vec = {4, 1, 1, 1, 1};
//	int* ptrArr = vec.data();
//
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
	spdlog::set_level(spdlog::level::trace);
	spdlog::trace("program started.");
	std::vector<int> a = { 1, 2, 5, 8 };
	std::vector<int> b = { 2, 4, 6 };

	std::vector<int> r = mergeArrays(a.data(), b.data(), a.size(), b.size());
	
	for (size_t i = 0; i < r.size(); ++i) {
		std::cout << r[i] << " ";
	} 
}