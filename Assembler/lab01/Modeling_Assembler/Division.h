#pragma once
#ifndef DIVISION_H
#define DIVISION_H
#include "Command.h"

class Division : public Command
{
public:
	int execute() const { operand_ /= value_; return operand_; }
	Division(int& operand, int value) : operand_(operand), value_(value) {}
private:
	int& operand_;
	int value_;
};

#endif // !DIVISION_H
