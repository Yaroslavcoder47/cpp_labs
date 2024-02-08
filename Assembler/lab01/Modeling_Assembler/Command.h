#pragma once
#ifndef COMMAND_H
#define COMMAND_H
#include "spdlog/spdlog.h"
#include "ProgramClass.h"

class Command
{
public:
	virtual int execute() const = 0;
	virtual ~Command() {};
};

#endif // !COMMAND_H