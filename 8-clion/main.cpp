#include <iostream>
#include "calculator.h"
#include "stack.h"

using namespace std;

int main() {
    Stack<int> stackInt;
    stackInt.push(10);
    cout << stackInt.peek() << " " << stackInt.getTop() << endl;
    stackInt.push(8);
    stackInt << 4 << -3;
    int number;
    stackInt >> number;
    cout << stackInt << " | top: " << stackInt.getTop() << endl;
    cout << "Number: " << number << endl;
    stackInt.pop();
    cout << stackInt << " | top: " << stackInt.getTop() << endl;

    Stack<char> stackChar;
    char ch;
    stackChar << '+' << '-' << '*' << '/' << '/' << '^';
    stackChar >> ch;
    cout << stackChar << "|| " << ch << endl;

    Calculator calc;
    std::string expression1 = "(4 + 9*(8-1)) / (3 - 6/8)";
    cout << "Postfix: " <<  calc.inFixToPostfix(expression1) << endl;
    cout << expression1 << " = " << calc.calculateExpression(expression1) << endl;

}