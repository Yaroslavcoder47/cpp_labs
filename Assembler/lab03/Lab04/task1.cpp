#include "task1.h"

std::vector<int> inputList(std::istream& stream, int size)
{
	std::vector<int> list(size + 1);
	list[0] = size;
	for (size_t i = 1; i < size; ++i) {
		stream >> list[i];
	}
	return list;
}

void deleteSameElements(std::list<int>& list)
{
	int size = list.size();
	list.push_front(size);
	std::vector<int> vec;
	for (auto tmp : list) {
		vec.push_back(tmp);
	}
	int* ptrArr = vec.data();
	int* n = ptrArr;
	for(int n = 1; )
}