#pragma once
#include <iostream>
#include <stdexcept>

template<typename T>
class Stack {
private:
    T* arr;         
    int capacity;   
    int top;        

public:
    Stack();
    ~Stack();
    int getTop() const;
    T* getArr() const;
    void push(const T &element);
    void push(const T* array, const int &array_size);
    T pop();
    T popElement(const int &index);
    bool isEmpty() const;

    T peek() const;
    T view(int index) const;

    bool operator==(const Stack<T>& other) const;
    bool operator<(const Stack<T>& other) const;
    bool operator>(const Stack<T>& other) const;
    bool operator!=(const Stack<T>& other) const;
    T operator[](const int& index) const;
    Stack<T>& operator=(const Stack& other);
    Stack<T>& operator<<(const T &elem);
    Stack<T>& operator>>(T &elem);
};

/*-----------------------------------------------------------*/

template<typename T>
Stack<T>::Stack() : capacity(25), top(-1) {
    arr = new T[capacity];
}

template<typename T>
Stack<T>::~Stack() {
    delete[] arr;
}

template<typename T>
int Stack<T>::getTop() const {
    return top;
}

template<typename T>
T* Stack<T>::getArr() const {
    return (T*)arr;
}

template<typename T>
void Stack<T>::push(const T &element) {
    if (top == capacity) {
        capacity *= 2;
        T* newArr = new T[capacity];
        for (int i = 0; i < top; ++i) {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
    }
    arr[++top] = element;
}

template<typename T>
void Stack<T>::push(const T* array, const int &array_size) {
    if (top == capacity - array_size) {
        throw std::overflow_error("Stack is overflow");
    }
    for (int i = 0; i < array_size; i++) {
        push(array[i]);
    }
}

template<typename T>
T Stack<T>::pop() {
    if (!isEmpty()) {
        return arr[top--];
    }
    throw std::underflow_error("Stack is empty");
}

template<typename T>
T Stack<T>::popElement(const int &index) {
    if (index < 0 || index > top) {
        throw std::underflow_error("Index is out of range");
    }
    T erase_element = arr[index];
    for (int i = index; i < top + 1; ++i) {
        arr[i] = arr[i + 1];
    }
    --top;
    return erase_element;
}

template<typename T>
T Stack<T>::view(int index) const {
    if (index < 1 || index > top) {
        throw std::out_of_range("Index out of range");
    }
    return arr[index];
}

template<typename T>
bool Stack<T>::isEmpty() const {
    return (top == -1);
}

template<typename T>
T Stack<T>::peek() const {
    if (isEmpty()) {
        throw std::underflow_error("Stack is empty");
    }
    return arr[top];
}

template<typename T>
bool Stack<T>::operator==(const Stack<T>& other) const {
    if (top != other.top)
        return false;
    for (int i = 0; i <= top; ++i) {
        if (arr[i] != other.arr[i])
            return false;
    }
    return true;
}

template<typename T>
bool Stack<T>::operator<(const Stack<T>& other) const {
    return (top < other.top);
}

template<typename T>
bool Stack<T>::operator>(const Stack<T>& other) const {
    return (top > other.top);
}

template<typename T>
bool Stack<T>::operator!=(const Stack<T>& other) const {
    return !(*this == other);
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& other) {
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

template<typename T>
T Stack<T>::operator[](const int& index) const {
    if ((index < 0) || (index >= top)) {
        throw std::out_of_range("Incorrect index");
    }
    return arr[index];
}

template<typename T>
Stack<T>& Stack<T>::operator<<(const T &elem) {
    this->push(elem);
    return *this;
}

template<typename T>
Stack<T>& Stack<T>::operator>>(T &elem) {
    if (!isEmpty()) {
        elem = arr[top--];
        return *this;
    }
    throw std::out_of_range("Stack is Empty");
}

template<typename T>
std::ostream& operator<<(std::ostream &out, const Stack<T> &stack) {
    for (int i = 0; i < stack.getTop() + 1; i++) {
        out << stack.getArr()[i] << " ";
    }
    return out;
}