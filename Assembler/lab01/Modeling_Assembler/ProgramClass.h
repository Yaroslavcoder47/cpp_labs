#pragma once
#ifndef PROGRAM_CLASS_H
#define PROGRAM_CLASS_H


class ProgramClass
{
public:
	void Calculate();
private:
	map<string, int> dataNumber;
};

void ProgramClass::Calculate()
{
	Parser p;
	dataNumber = p.parseData("input.txt", 1);
}
#endif // !PROGRAM_CLASS_H