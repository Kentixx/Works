#include <sstream>
#include <stdexcept>
#include <cctype>

const auto operators = {'+', '-', '*', '/'};

bool Calculator::isOperator(char c) {
	if (std::find(operators.begin(), operators.end(), )) {
		return true;
	}
	return false;
}

int Calculator::precedence(char op) {
	switch (op){
		case '+':
		case '-' :
			return 1;
		case '*':
		case '/':
			return 2;
}
	return 0;
}

std::string Calculator::infixToPostfix(const std::string& expr){
	std::stringstream output;
	for (char c : expr) {
		if (std::isdigit(c) || c == '.') {
			output << c;
		} else if(c == '(') {
			operators << c;
		} else if (c == ')') {
			char top;
			operators >> top;
			while (top != '(') {
				output << ' ' << top;
				operators >> top;
			}
		}
		else if (isOperator(c)) {
			output << ' ';
			char top;
			while (!operators.isEmpty()) {
				operators >> top;
				if (precedence(top) >= precedence(c)) {
					output << top << ' ';
				}
				else {
					operators << top;
					break;
				}
			}
			operators << c;
		} else {
			return "";
		
		}
	}
	while (!operators.isEmpty()) {
		char top;
		operators >> top;
		if (top == '(') {
			return "";
		}
		output << ' ' << top;
	}
	return output.str();
}

double Calculator::calculatePostfix(const std::string& postfix){
	Stack<double> operands;
	std::stringstream ss(postfix);
	std::string symbol;
	while (ss >> symbol) {
		if (std::isdigit(symbol[0]) || (symbol.size() > 1 && std::isdigit(symbol[1]))) {
			operands << std::stod(symbol);
		} else if (isOperator(symbol[0]) && symbol.size() == 1) {
			double b;
			double a;
			operands >> b;
			operands >> a;
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
					operands << (a / b);
					break;
			}
		}
	}
	double result;
	operands >> result;
	return result;
}

bool Calculator::processExpr(const std::string& expr){
	//std::string postfix = infixToPostfix(expr);
	return isCorrectExpr(expr) && !infixToPostfix(expr).empty();
}

bool Calculator::isCorrectExpr(const std::string& expr){
	int count = 0;
	for (char c : expr) {
		if (c == '(') {
			++count;
		}
		else if (c == ')') {
			--count;
			if (count < 0) {
				return false;
			}
		}
	}
	return count == 0;
}

double Calculator::calculateExpr(const std::string& expr){
	std::string postfix = infixToPostfix(expr);
	if (postfix.empty()) {
		throw std::exception("Invalid expr");
	}
	return calculatePostfix(postfix);
}

/*int Calculator::evaluate(const std::string& expression) {
    Stack<int> stack;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            stack.push(std::stoi(token));
        } else {
            // В противном случае, это оператор
            int b = stack.pop();
            int a = stack.pop();
            switch (token[0]) {
                case '+':
                    stack.push(a + b);
                    break;
                case '-':
                    stack.push(a - b);
                    break;
                case '*':
                    stack.push(a * b);
                    break;
                case '/':
                    if (b == 0) throw std::runtime_error("Деление на ноль");
                    stack.push(a / b);
                    break;
                default:
                    throw std::runtime_error("Неизвестный оператор");
            }
        }
    }

    return stack.pop(); // Результат в верхнем элементе стека
}*/