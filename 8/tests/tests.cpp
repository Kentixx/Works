#include "./lib/googletest/include/gtest/gtest.h"
#include "../calculator.h"
#include "../stack.h"

class StackTest : public ::testing::Test {
    protected:
    Stack<int> stackInt;
    Stack<int> stackInt2;
    Stack<double> stackDouble;
    Stack<double> stackDouble2;
    Stack<char> stackChar;
    Stack<std::string> stackString;
};

class CalculatorTest : public ::testing::Test {
    protected:
    Calculator calc;
};

/*-------------------------------------------------------*/

TEST_F(StackTest, PushingInt) {
    stackInt.push(5);
    stackInt << -4 << 35;
    ASSERT_EQ(stackInt.view(1), -4);
}

TEST_F(StackTest, PushingDouble) {
    stackDouble.push(523.32092);
    stackDouble << 64.3 << 202.45;
    stackDouble.push(12);
    ASSERT_EQ(stackDouble[2], 202.45);
}

TEST_F(StackTest, PushingChar) {
    stackChar << 'a' << '#' << '*' << '\n';
    char charArray[5] = {'p', 'R', 'K', '4', 'A'};
    stackChar.push(charArray, 5);
    ASSERT_NE(stackChar[2], 'R');
    ASSERT_EQ(stackChar.peek(), 'A');
    ASSERT_EQ(stackChar.view(4), 'p');
}

TEST_F(StackTest, PopingInt) {
    stackInt << 6 << 35 << -8;
    ASSERT_NE(stackInt.pop(), 35);
    ASSERT_EQ(stackInt.pop(), 35);
}

TEST_F(StackTest, PopingChar) {
    char chars[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    char element;
    stackChar.push(chars, 10);
    stackChar >> element;
    ASSERT_EQ(element, 'j');
}

TEST_F(StackTest, PopingElementByValue) {
    int numbers[10] = {35, 0, 16, -45, 1089, 52, 3, 1, 843, 565};
    stackInt.push(numbers, 10);
    ASSERT_EQ(stackInt.popElement(3), -45);
    ASSERT_EQ(stackInt.popElement(7), 843);
}

TEST_F(StackTest, AreStacksEqual) {
    stackInt << -8 << 35 << 2;
    stackInt2.push(-8);
    stackInt2.push(35);
    stackInt2.push(2);
    ASSERT_TRUE(stackInt == stackInt2);
    stackInt2.popElement(0);
    ASSERT_TRUE(stackInt != stackInt2);
}

TEST_F(StackTest, StacksCompare) {
    stackDouble << 8.3 << 202.45 << 0;
    double numbers[5] = {5.7, 3.98, 0.212121, 7.002, 52.52};
    stackDouble2.push(numbers, 5);
    ASSERT_TRUE(stackDouble < stackDouble2);
    stackDouble << 6.7 << 24.6;
    ASSERT_FALSE(stackDouble > stackDouble2);
}

TEST_F(StackTest, StacksAssign) {
    stackString << "This" << "is" << "a" ;
    stackString << "stack" << "of" << "strings";
    Stack<std::string> stackString2 = stackString;
    ASSERT_EQ(stackString[2], "a");
    ASSERT_THROW(stackString2[6], std::out_of_range);
}

/*-------------------------------------------------------*/

// К сожалению, я не смог разобраться с ошибками "undefined reference to ..."

TEST_F(CalculatorTest, OperatorChecking) {
    ASSERT_TRUE(calc.isOperator('/'));
    ASSERT_FALSE(calc.isOperator('('));
}

TEST_F(CalculatorTest, PrecedenceChecking) {
    ASSERT_EQ(calc.precedence('/'), 2);
    ASSERT_NE(calc.precedence('+'), 0);
}

TEST_F(CalculatorTest, InFixtoPostfixEqual) {
    ASSERT_EQ(calc.inFixToPostfix("(2+6)/(7-14) + 35.6"), "2 6 + 7 14 - / 35.6 +");
    ASSERT_NE(calc.inFixToPostfix("5 + (4 - 30/6) * (-8) + 6"), "5 4 30 6 / - 8 - * + 6 +");
}

TEST_F(CalculatorTest, InFixtoPostfixErrors) {
    ASSERT_THROW(calc.inFixToPostfix("10 - 6.3& + 1"), std::invalid_argument);
    ASSERT_THROW(calc.inFixToPostfix("(5+7/2"), std::invalid_argument);
    ASSERT_THROW(calc.inFixToPostfix("4*(65.3-12/53)( - 45) 2)"), std::invalid_argument);
}

TEST_F(CalculatorTest, CalculatePostfix) {
    ASSERT_EQ(calc.calculatePostfix("5 4 30 6 / - 8 - * + 6 +"), 19);
    ASSERT_THROW(calc.calculatePostfix("38 2 0 / - 3 +"), std::runtime_error);
    ASSERT_THROW(calc.calculatePostfix("4 9 8 1 - * + #@ 3 6 8 / - /"), std::runtime_error);
}

TEST_F(CalculatorTest, IsCorrectExpression) {
    ASSERT_TRUE(calc.isCorrectExpression("(2 + 6 / 7) * 8"));
    ASSERT_FALSE(calc.isCorrectExpression("(5+7/2"));
}

TEST_F(CalculatorTest, CalculateExpression) {
    ASSERT_EQ(calc.calculateExpression("(2 + 6 / 2) * 8"), 40);
    ASSERT_EQ(calc.calculateExpression("(4 + 9*(2-8)) / (4 - (-3)*7)"), -2);
}
