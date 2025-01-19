#include "stack.h"
#include "calculator.h"
#include "stack.cpp"
#include <ctime>
#include <cstdlib>
#include <iostream>

int main() {
    Stack<int> stack_int;
    for (int i = 0; i < 10; i++) {
        stack_int.push(rand() % 1000);
    }
    stack_int.output();
    stack_int.pop();
    stack_int.pop();
    stack_int.push(52);
    std::cout << "2 элемент стека: " << stack_int.view(1) << std::endl;
    stack_int.output();
    //std::cout << "12 элемент стека: " << stack_int.view(12) << std::endl;
}