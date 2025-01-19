#pragma once
#include <iostream>
#include <stdexcept>

template<typename T>
class Stack {
protected:
    T* arr;         
    int capacity;   
    int top;        

public:
    Stack(int size = 10);
    ~Stack();

    void push(T element);
    T pop();
    bool isEmpty() const;
    T peek() const;
    T view(int index) const;
    void output() const;

    bool operator==(const Stack<T>& other) const;
    bool operator!=(const Stack<T>& other) const;
    Stack<T>& operator=(const Stack& other);
};

template<typename T>
std::ostream& operator<<(std::ostream &out, const Stack<T> &stack);