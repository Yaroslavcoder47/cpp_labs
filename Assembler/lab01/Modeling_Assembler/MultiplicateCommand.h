#pragma once
#ifndef MULTIPLICATE_COMMAND_H
#define MULTIPLICATE_COMMAND_H
#include "Command.h"


class MultiplicateCommand : public Command
{
public:
	int execute(const int& a, const int& b) const override;
};

#endif !MULTIPLICATE_COMMAND_H
