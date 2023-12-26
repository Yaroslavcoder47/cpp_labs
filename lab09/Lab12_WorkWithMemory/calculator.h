#pragma once
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string>
#include <iostream>
#include <iomanip>
#include <utility>
#include "../Lab12_WorkWithMemory/StackOnList.h"

int getPriorityOfOperation(char operation) {
    if (operation == '+' || operation == '-') {
        return 1;
    }
    else if (operation == '*' || operation == '/') {
        return 2;
    }
    return 0;
}

std::string makePostfix(const std::string& formula) {
    StackOnList<char> operators;
    std::string postfix;

    for (char ch : formula) {
        if (std::isalnum(ch)) {
            postfix += ch;  
        }
        else if (ch == '(') {
            operators.push(ch);  
        }
        else if (ch == ')') {
            while (!operators.isEmpty() && operators.top() != '(') {
                postfix += operators.top();
                operators.pop();
            }
            operators.pop();  
        }
        else {
            while (!operators.isEmpty() && getPriorityOfOperation(operators.top()) >= getPriorityOfOperation(ch)) {
                postfix += operators.top();
                operators.pop();
            }
            operators.push(ch);
        }
    }

    while (!operators.isEmpty()) {
        postfix += operators.top();
        operators.pop();
    }

    return postfix;
}

int calculate(const std::string& formula)
{
    std::string postfixFormula = makePostfix(formula);
    StackOnArray<int> numbers;
    for (const auto& it : postfixFormula) {
        if (it >= 48 && it <= 57) {
            numbers.push(it - '0');
        }
        else {
            int res;
            switch (it)
            {
            case '+':
                res = numbers.pop();
                numbers.top() += res;
                break;
            case '-':
                res = numbers.pop();
                numbers.top() -= res;
                break;
            case '*':
                res = numbers.pop();
                numbers.top() *= res;
                break;
            case '/':
                res = numbers.pop();
                numbers.top() /= res;
                break;
            default:
                break;
            }
        }
    }
    return numbers.top();
}

#endif // CALCULATOR_H

