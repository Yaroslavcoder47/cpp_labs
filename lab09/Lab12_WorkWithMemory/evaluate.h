#pragma once
#ifndef EVALUATE_H
#define EVALUATE_H

#include <string>
#include <iostream>
#include <iomanip>
#include <utility>
#include "../Lab12_WorkWithMemory/StackOnList.h"

int findMax(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}

int findMin(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}


int evaluate(std::string formula)
{
	StackOnList<int> arguments;
	StackOnList<char> brackets;
	StackOnList<char> operations;
	for (const auto& element : formula) {
			if (element == 'a' || element == 'i') {
				operations.push(element);
			}
			if (element == '(') {
				brackets.push(element);
			}
			if (element >= 48 && element <= 57) {
				arguments.push(element - '0');
			}
			if (element == ')') {
				if (!brackets.isEmpty()) {
					if (operations.pop() == 'a') {
						int res = findMax(arguments.pop(), arguments.pop());
						arguments.push(res);
						brackets.pop();
					}
					else {
						int res = findMin(arguments.pop(), arguments.pop());
						arguments.push(res);
						brackets.pop();
					}
				}
				else {
					throw std::invalid_argument("Wrong formula");
				}
			}
		}
		return arguments.top();
}

#endif // EVALUATE_H
