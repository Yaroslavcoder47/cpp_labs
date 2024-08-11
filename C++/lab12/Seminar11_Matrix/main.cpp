#include <iostream>
#include <vector>
#include <fstream>
#include "spdlog/spdlog.h"
#include "Array.h"
#include "ArrayService.h"
#include "Matrix.h"
#include "MatrixService.h"

using std::cin;
using std::cout;
using std::vector;


int main()
{
	try {
		spdlog::set_level(spdlog::level::debug);
		spdlog::info("Start");

		std::ofstream fout("output.txt");
		std::ifstream fin("input.txt");
		Matrix<double> v(2, 2);
		fin >> v;
		std::ifstream fin1("input1.txt");
		Matrix<double> v1(2, 2);
		fin1 >> v1;
		Matrix<double> v2 = solveEquation(v, v1);
		fout << v2;

		spdlog::info("End");
	}
	catch (const std::exception& ex) {
		std::cerr << ex.what();
	}
	
	return 0;
}