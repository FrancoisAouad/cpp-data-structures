#include "./queue.interface.h"
#include "stdexcept"

template <typename T>
class ArrayQueue : public QueueInterface<T> {
private:
    int capacity;
    int size;
    int head;
    int tail;
    T* data;
public:
    ArrayQueue(int capacity) : capacity(capacity), size(0), head(0), tail(-1) {
        if (capacity <= 0) {
            throw std :: invalid_argument("Queue capacity must be positive");
        }
        data = new T[capacity];
    }

    virtual ~ArrayQueue() {
        delete[] data;
    }

    void enqueue(const T& val) override {
        if (size == capacity) {
            throw std :: overflow_error("Queue is full.");
        }
        ++size;
        tail = (tail + 1) % capacity;
        data[tail] = val;
    }

    T dequeue() override {
        if (size == 0) {
            throw std :: underflow_error("Queue is empty.");
        }
        --size;
        T val = data[head];
        head = (head + 1) % capacity;
        return val;
    }

    bool isEmpty() const override {
        return size == 0;
    }

    bool isFull() const override {
        return size == capacity;
    }

    const T& front() const override {
        if (size == 0) {
            throw std :: underflow_error("Queue is empty.");
        }
        return data[head];
    }
};