/**
* ƒаны N чисел. N - 1 раз делают следующее - берут два минимальных числа, 
* выкидывают их из массива и добавл€ют их сумму. Ќа каждом шаге алгоритма выводите 
* минимум и максимум в массиве.
*/

#include <iostream>
#include <vector>
#include "libraryVector.h"

using std::vector;
using namespace std;

int main()
{
	vector<size_t> container;

	container = readVector("data/input.txt", container);
	changeVector("data/output.txt", container);
	return 0;
}