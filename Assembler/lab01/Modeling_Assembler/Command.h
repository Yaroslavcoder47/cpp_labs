#pragma once
#ifndef COMMAND_H
#define COMMAND_H
#include <spdlog/spdlog.h>
class Command
{
public:
	static int multiplication(const int& a, const int& b);
	static int addition(const int& a, const int& b);
	static int division(const int& a, const int& b);
	static int subtraction(const int& a, const int& b);
};

#endif // !COMMAND_H