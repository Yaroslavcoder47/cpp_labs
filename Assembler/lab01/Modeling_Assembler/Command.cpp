#include "Command.h"

int Command::multiplication(const int& a, const int& b)
{
	spdlog::debug("Multicplicate {0:d}, {1:d}", a, b);
	return a * b;
}

int Command::addition(const int& a, const int& b)
{
	spdlog::debug("Addition {0:d}, {1:d}", a, b);
	return a + b;
}

int Command::division(const int& a, const int& b)
{
	if (b == 0) {
		spdlog::error("Division by zero");
		throw std::invalid_argument("Divivsion by zero");
	}
	spdlog::debug("Division {0:d}, {1:d}", a, b);
	return a / b;
}

int Command::subtraction(const int& a, const int& b)
{
	spdlog::debug("Subtraction {0:d}, {1:d}", a, b);
	return a - b;
}