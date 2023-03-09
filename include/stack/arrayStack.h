#include "./stack.interface.h"
#include "stdexcept"

template <typename T>
class arrayStack : public StackInterface<T> {
private:
    int capacity;
    int size;
    int top_index;
    T* data;
public:
    // Constructor
    arrayStack(int capacity) : capacity(capacity), size(0), top_index(-1) {
        if (capacity <= 0) {
            throw std::invalid_argument("Stack capacity must be positive");
        }
        data = new T[capacity];
    }

    // Destructor
     ~arrayStack() {
        delete[] data;
    }

    void push(T val) override {
        if (size == capacity) {
            throw std::overflow_error("Stack is full.");
        }
        ++size;
        data[++top_index] = val;
    }

    T pop() override {
        if (size == 0) {
            throw std::underflow_error("Stack is empty.");
        }
        --size;
        return data[top_index--];
    }

    bool isEmpty() const override {
        return size == 0;
    }

    bool isFull() const override {
        return size == capacity;
    }

    T top() const override {
        if (size == 0) {
            throw std::underflow_error("Stack is empty.");
        }
        return data[top_index];
    }
};