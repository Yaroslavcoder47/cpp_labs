/**
* Во входном файле строки из маленьких латинских букв, вывести количество 
*различных строк. 
*/

// Test cases
//
//		Strings			numberOfDifferentStrings
//						
//		rjgbt				7
//		dee
//		apple
//		afrple
//		red
//		apple
//		ref
//		red
//		red
//		jou
//		dee

#include <iostream>
#include <set>
#include <fstream>
#include <string>
#include <vector>
#include "libraryContainer.h"

using std::set;
using std::ifstream;
using std::ofstream;
using std::string;
using std::vector;

int main()
{
	vector<string> container;
	container = readStrings("data/strings.txt");
	int numberOfElements;

	numberOfElements = findDifferentElements(container);

	printNumberOfDifferentElements("data/output.txt", numberOfElements);
	return 0;
}