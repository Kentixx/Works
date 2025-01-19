#pragma once
#include "stack.h"
#include <string>
#include <cctype>
#include <sstream>

class Calculator {
private:
	Stack<char> operators;
	Stack<double> operands;
public:
	static bool isOperator(const char &c);
	static int precedence(const char &oper);
	bool processExpression(const std::string& expr);
	bool isCorrectExpression(const std::string& expr);
	double calculateExpression(const std::string& expr);
	std::string inFixToPostfix(const std::string& expr);
	double calculatePostfix(const std::string& postfix);
};
