#include <gtest/gtest.h>
#include "../calculator.h"
#include "../stack.h"

TEST(StackPushTest, PushingInt) {
    Stack<int> stack;
    stack.push(8);
    ASSERT_NE(stack[1], 5);
}

TEST(StackPushTest, PushingDouble) {
    Stack<double> stack;
    stack.push(523.32092);
    stack << 64.3 << 202.45;
    stack.push(12);
    ASSERT_EQ(stack[3], 202.45);
}

TEST(CalculatorTests, OperatorsCheck) {
    Calculator calc;
    bool plus = calc.isOperator('+');
    ASSERT_TRUE(plus);
}