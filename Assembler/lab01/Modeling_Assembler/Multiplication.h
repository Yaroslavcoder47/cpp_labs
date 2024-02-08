#pragma once
#ifndef MULTIPLICATION_H
#define MULTIPLICATION_H
#include "Command.h"

class Multiplication : public Command
{
public:
	int execute() const { operand_ *= value_; return operand_; }
	Multiplication(int& operand, int value) : operand_(operand), value_(value) {}
private:
	int& operand_;
	int value_;
};

#endif // !MULTIPLICATION_H