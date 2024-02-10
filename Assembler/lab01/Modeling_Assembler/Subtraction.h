#pragma once
#ifndef SUBTRACTION_H
#define SUBTRACTION_H
#include "Command.h"

class Subtraction : public Command
{
public:
	int execute() const { spdlog::debug("Subtraction {0:d}, {1:d}", operand_, value_);  operand_ -= value_; return  operand_; }
	Subtraction(int& operand, int value) : operand_(operand), value_(value) {}
private:
	int& operand_;
	int value_;
};

#endif // !SUBTRACTION_H