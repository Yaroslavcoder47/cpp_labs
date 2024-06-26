#pragma once
#ifndef ADDITION_H
#define ADDITION_H
#include "Command.h"

class Addition : public Command
{
public:
	int execute() const { spdlog::debug("Addition {0:d}, {1:d}", operand_, value_); operand_ += value_; return operand_; }
	Addition(int& operand, int value) : operand_(operand), value_(value) {}
private:
	int& operand_;
	int value_;
};

#endif // !ADDITION_H