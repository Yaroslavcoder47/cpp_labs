#include <iostream>
#include <vector>
#include "sorting_algorithms.h"
#include "iodata.h"
#include "data_generation.h"
#include <chrono>
#include <string>
#include <ctime>

using namespace std::chrono;
int main()
{
	const int size = 100;
	const int numberOfElements = 100;
	std::vector<int> arrayAscending = generateDataAscending(size);
	std::vector<int> arrayRandom = generateDataRandom(size, numberOfElements);
	std::vector<int> arrayDescending = generateDataDescending(size);
	
	//input data to file
	std::string fileName = "input_" + std::to_string(size) + "_int_ascending.txt";
	std::string filePath = "data/" + fileName;
	writeData(arrayAscending, filePath);
	arrayAscending = readData(filePath);

	fileName = "input_" + std::to_string(size) + "_int_descending.txt";
	filePath = "data/" + fileName;
	writeData(arrayDescending, filePath);
	arrayDescending = readData(filePath);
	
	fileName = "input_" + std::to_string(size) + "_int_random.txt";
	filePath = "data/" + fileName;
	writeData(arrayRandom, filePath);
	arrayRandom = readData(filePath);

	// time for algorithms of sorting
	auto start = system_clock::now();
	insertionSort(arrayRandom);
	auto end = system_clock::now();
	auto elapsed_seconds = duration_cast<seconds>(end - start).count();
	auto elapsed_milliseconds = duration_cast<microseconds>(end - start).count();
	std::time_t end_time = system_clock::to_time_t(end);
#pragma warning(suppress : 4996)
	std::cout << "Calculations are finished on " << std::ctime(&end_time) << "Algorithm execution time: "
		<< elapsed_seconds << "s\n" << "Algorithm execution time: " << elapsed_milliseconds << "mcs\n";


}