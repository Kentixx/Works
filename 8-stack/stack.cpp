#include "stack.h"

template<typename T>
Stack<T>::Stack(int size) : capacity(size), top(-1) {
    arr = new T[capacity];
}

template<typename T>
Stack<T>::~Stack() {
    delete[] arr;
}

template<typename T>
void Stack<T>::push(T element) {
    if (top == capacity - 1) {
        throw std::overflow_error("Стек переполнен");
    }
    arr[++top] = element;
}

template<typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::underflow_error("Стек пуст");
    }
    return arr[top--];
}

template<typename T>
bool Stack<T>::isEmpty() const {
    return top == -1;
}

template<typename T>
T Stack<T>::peek() const {
    if (isEmpty()) {
        throw std::underflow_error("Стек пуст");
    }
    return arr[top];
}

template<typename T>
T Stack<T>::view(int index) const {
    if (index < 0 || index > top) {
        throw std::out_of_range("Индекс вне диапазона");
    }
    return arr[index];
}

template<typename T>
void Stack<T>::output() const {
    for (int i = 0; i < top; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
bool Stack<T>::operator==(const Stack<T>& other) const {
    if (top != other.top) return false;
    for (int i = 0; i <= top; ++i) {
        if (arr[i] != other.arr[i]) return false;
    }
    return true;
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