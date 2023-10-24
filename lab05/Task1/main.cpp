/**
*1. Даны два множества A и B (std::multiset). Найти объединение (A U B), пересечение 
*(A ∩ B), разность этих множеств (A / B, B / A).
*/

// Test cases
//
//	set A			set B			Union			Intersection		A / B		B / A
//	1 5 3 2 4		6 2 3 4 5 9		1 2 3 4 5 6 9	2 3 4 5				1			6 9

#include <iostream>
#include <set>
#include <fstream>
#include <string>
#include "libraryContainer.h"

using std::multiset;
using std::ifstream;
using std::ofstream;
using std::string;

int main()
{
	multiset<string> container1;
	multiset<string> container2;

	container1 = readMultiset("data/set1.txt");
	container2 = readMultiset("data/set2.txt");

	multiset<string> setUnion;
	setUnion = multisetUnion(container1, container2);

	multiset<string> setIntersection;
	setIntersection = multisetIntersection(container1, container2);

	multiset<string> setDifference1;
	setDifference1 = multisetDifference(container1, container2);

	multiset<string> setDifference2;
	setDifference2 = multisetDifference(container2, container1);

	printMultiset("Union", "data/output.txt", setUnion);
	printMultiset("Intersection", "data/output.txt", setIntersection);
	printMultiset("A / B", "data/output.txt", setDifference1);
	printMultiset("B / A", "data/output.txt", setDifference2);
	return 0;
}