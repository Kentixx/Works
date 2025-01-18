#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T>
class Stack {
private:
    T* arr;         
    int capacity;   
    int top;        

public:
    Stack() : capacity(25), top(0) {
        arr = new T[capacity];
    }
    Stack(int size) : capacity(size), top(-1) {
        arr = new T[capacity];
    }
    ~Stack() {
        delete[] arr;
    }

    void push(const T &element) {
        if (top == capacity - 1) {
            throw std::overflow_error("Stack is overflow");
        }
        arr[++top] = element;
    }

    void push(const T* array, const int &array_size) {
        if (top == capacity - array_size) {
            throw std::overflow_error("Stack is overflow");
        }
        for (int i = 0; i < array_size; i++) {
            push(array[i]);
        }
    }

    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return arr[top--];
    }

    T popElement(const int &index) {
        if (index < 0 || index > top) {
            throw std::underflow_error("Index is out of range");
        }
        T erase_element = arr[index + 1];
        for (int i = index + 1; i < top; ++i) {
            arr[i] = arr[i + 1];
        }
        --top;
        return erase_element;
    }

    bool isEmpty() const {
        return top == -1;
    }

    T peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }
        return arr[top];
    }

    T view(int index) const {
        if (index < 1 || index > top) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index + 1];
    }

    void output() const {
        for (int i = 1; i < top + 1; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    bool operator==(const Stack<T>& other) const {
        if (top != other.top)
            return false;
        for (int i = 0; i <= top; ++i) {
            if (arr[i] != other.arr[i])
                return false;
        }
        return true;
    }
    bool operator<(const Stack<T>& other) const {
        return (top < other.top);
    }
    bool operator>(const Stack<T>& other) const {
        return (top > other.top);
    }
    bool operator!=(const Stack<T>& other) const {
        return !(*this == other);
    }
    T operator[](const int& index) const {
        return arr[index];
    }
    Stack<T>& operator=(const Stack& other) {
        if (this == &other) {
            return *this;
        }
        delete[] arr;
        top = other.top;
        capacity = other.capacity;
        arr = new T[capacity];
        for (int i = 0; i < top; ++i) {
            arr[i] = other.arr[i];
        }
        return *this;
    }
};

template<typename T>
Stack<T>& operator<<(Stack<T> &stack, const T &elem) {
    stack.push(elem);
    return stack;
}
template<typename T>
Stack<T>& operator>>(Stack<T> &stack, const T &index) {
    stack.popElement(index);
    return stack;
}