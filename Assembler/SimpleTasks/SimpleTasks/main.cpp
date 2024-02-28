#include <iostream>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "task1.h"

using std::cout;
using std::cin;

int main()
{
	auto logger = spdlog::basic_logger_mt("Lab03_main", "../Logs/Lab03Logger.txt");
	logger->set_level(spdlog::level::info);
	logger.get()->info("Application started");
	cout << task1(2405).first << ' ' << task1(458).second;
	logger.get()->info("Application ended");
	return 0;
}