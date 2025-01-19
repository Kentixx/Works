#ifndef CALCULATOR_H
#define CALCULATOR_H

#pragma once
#include "stack.h"
#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <sstream>

class Calculator {
private:
	Stack<char> operators;
	//Stack<double> operands;
	int precedence(char op);
	
public:
	bool processExpr(const std::string& expr);
	bool isCorrectExpr(const std::string& expr);
	double calculateExpr(const std::string& expr);
	bool isOperator(char c);
	std::string infixToPostfix(const std::string& expr);
	double calculatePostfix(const std::string& postfix);
};


#endif