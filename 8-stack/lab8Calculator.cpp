#include "..\lab8Calculator\Calculator.h"
int main() {
    Calculator calculator;
    std::string expr;
    std::cout << "Input expression: ";
    std::getline(std::cin, expr);
    if (calculator.isCorrectExpr(expr)){ 
        try { double result = calculator.calculateExpr(expr);
        std::cout << "Result: " << result << std::endl;
        } catch (const std::invalid_argument& err) { 
            std::cout << "Error: " << err.what() << std::endl;
        }
    }
    else { 
        std::cout << "Incorrect expr" << std::endl;
    }
    return 0;
}