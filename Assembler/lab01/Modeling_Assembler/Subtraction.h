#pragma once
#ifndef SUBTRACTION_H
#define SUBTRACTION_H
#include "Command.h"

class Subtraction : public Command
{
public:
	int execute() const { operand_ -= value_; return  operand_; }
	Subtraction(int& operand, int value) : operand_(operand), value_(value) {}
private:
	int& operand_;
	int value_;
};

#endif // !SUBTRACTION_H