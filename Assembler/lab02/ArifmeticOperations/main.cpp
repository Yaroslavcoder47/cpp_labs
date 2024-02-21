#include <iostream>
#include <vector>
#include "Task3.h"
#include "Task4.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"


using std::cin;
using std::cout;
using namespace std;


int main()
{
	try {
		auto logger = spdlog::basic_logger_mt("Lab02_main", "Lab02Logger.txt");
		logger.get()->info("Start project");

		uint16_t a1 = 0xFFFF;
		uint16_t a2 = 0x0000;
		uint16_t a3 = 0x0000;
		uint16_t b1 = 0x0001;
		uint16_t b2 = 0x0000;
		uint16_t b3 = 0x0000;

		//expectedResult = { 0x0000, 0x0001, 0x0000, 0x0000 };
		std::vector<uint16_t>realResult = task4(a1, a2, a3, b1, b2, b3);
		for (int i = 0; i < realResult.size(); ++i) {
			std::cout << std::hex << realResult[i] << std::endl;
		}


		logger.get()->info("End project");
	}
	catch (const spdlog::spdlog_ex& ex) {
		std::cerr << "Log is failed: " << ex.what() << '\n';
	}
	return 0;
}
