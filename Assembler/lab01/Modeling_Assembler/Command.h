#pragma once
#ifndef COMMAND_H
#define COMMAND_H
class Command
{
public:
	~Command() = default;
	virtual int execute(const int&, const int&) const = 0;
};

#endif // !COMMAND_H