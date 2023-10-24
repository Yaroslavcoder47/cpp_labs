/**
* Есть N задач, каждая выполняется раз в a[i] секунд . На секунде 0 выполнились все 
* задачи (то есть первая будет в 0, a[1], 2*a[1] ...). Вывести K первых выполнений. Если две 
* задачи в одну и ту же секунду выполняются, то первой вывести с меньшим номером. 
* (std:pair<int, int>) 
*/

#include <iostream>
#include <vector>
#include "library.h"

using std::vector;
using std::pair;

int main()
{
	vector<int> container;
	int n; // number of elements
	int k; // number of executions
	inputData(container, n, k);
	solution(container, k);
	return 0;
}