#include "calculator.h"

bool Calculator::isOperator(const char &c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int Calculator::precedence(const char &oper) {
	switch (oper) {
		case '+':
		case '-' :
			return 1;
		case '*':
		case '/':
			return 2;
		default: return 0;
	}
}

std::string Calculator::inFixToPostfix(const std::string& expression) {
	std::stringstream output;
	std::string numberBuffer;
	bool expectNumber = true;
	for (size_t i = 0; i < expression.size(); ++i) {
		char ch = expression[i];
		if (std::isspace(ch)) {
			continue;
		}
		if (std::isdigit(ch) || ch == '.') {
			numberBuffer += ch;
			expectNumber = false; // После числа ожидается оператор
		} else {
			if (!numberBuffer.empty()) {
				output << numberBuffer << ' ';
				numberBuffer.clear();
			}
			if (ch == '(') {
				operators.push(ch);
				expectNumber = true;
			} else if (ch == ')') {
				// Закрывающая скобка
				while (!operators.isEmpty() && operators.peek() != '(') {
					output << operators.pop() << ' ';
				}
				if (!operators.isEmpty() && operators.peek() == '(') {
					operators.pop();
				} else {
					throw std::invalid_argument("Mismatched brackets in expression");
				}
				expectNumber = false;
			} else if (isOperator(ch)) {
				if (ch == '-' && expectNumber) {
					numberBuffer += ch;
				} else {
					while (!operators.isEmpty() &&
					       precedence(operators.peek()) >= precedence(ch)) {
						output << operators.pop() << ' ';
					}
					operators.push(ch);
					expectNumber = true;
				}
			} else {
				throw std::invalid_argument("Invalid character in expression");
			}
		}
	}
	if (!numberBuffer.empty()) {
		output << numberBuffer << ' ';
	}
	while (!operators.isEmpty()) {
		if (operators.peek() == '(' || operators.peek() == ')') {
			throw std::invalid_argument("Mismatched brackets in expression");
		}
		output << operators.pop() << ' ';
	}
	return output.str();
}


double Calculator::calculatePostfix(const std::string& postfix) {
	Stack<double> operands;
	std::stringstream ss(postfix);
	std::string symbol;
	double result;
	while (ss >> symbol) {
		if (std::isdigit(symbol[0]) || (symbol[0] == '-' && symbol.size() > 1 && std::isdigit(symbol[1]))) {
			operands << std::stod(symbol);
		} else if (isOperator(symbol[0]) && symbol.size() == 1) {
			double b = operands.peek();
			operands.pop();
			double a = operands.peek();
			operands.pop();
			switch (symbol[0]) {
				case '+':
					operands << (a + b);
				break;
				case '-':
					operands << (a - b);
				break;
				case '*':
					operands << (a * b);
				break;
				case '/':
					if (b == 0) throw std::runtime_error("Division by zero");
				operands << (a / b);
				break;
			}
		} else {
			throw std::runtime_error("Invalid symbol in postfix expression");
		}
	}
	operands >> result;
	return result;
}

bool Calculator::processExpression(const std::string& expr){
	std::string postfix = inFixToPostfix(expr);
	return isCorrectExpression(expr) && !inFixToPostfix(expr).empty();
}

bool Calculator::isCorrectExpression(const std::string& expr){
	int countBrackets = 0;
	for (char ch : expr) {
		switch (ch) {
			case ')':
				++countBrackets;
			break;
			case '(':
				--countBrackets;
			break;
		}
		if (countBrackets < 0) {
			return false;
		}
	}
	return countBrackets == 0;
}

double Calculator::calculateExpression(const std::string& expr){
	std::string postfix = inFixToPostfix(expr);
	if (postfix.empty()) {
		throw std::invalid_argument("Invalid expression");
	}
	return calculatePostfix(postfix);
}
