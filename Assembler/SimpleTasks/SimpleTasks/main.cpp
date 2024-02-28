#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"

using std::cout;
using std::cin;

int main()
{
	try {
		auto logger = spdlog::basic_logger_mt("Lab03_main", "../Logs/Lab03Logger.txt");
		logger->set_level(spdlog::level::info);
		logger.get()->info("Application started");

		cout << task3(2, 30);

		logger.get()->info("Application ended");
	}
	catch (const spdlog::spdlog_ex& ex)
	{
		std::cout << "Log init failed: " << ex.what() << std::endl;
	}
	
	return 0;
}