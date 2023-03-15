#include "stdexcept"
#include "./list.interface.h"

template <typename T>
class ArrayList : public ListInterface<T> {
private:
    int capacity;
    int size;
    T* data;

public:
    // Constructor
    ArrayList(int capacity) : capacity(capacity), size(0) {
        if (capacity <= 0) {
            throw std :: invalid_argument("List capacity must be positive");
        }
        data = new T[capacity];
    }

    // Destructor
     ~ArrayList() {
        delete[] data;
    }

    void add(T value) override {
        if (size == capacity) {
            throw std :: overflow_error("List is full.");
        }
        data[size++] = value;
    }

    void remove(int index) override {
        if (index < 0 || index >= size) {
            throw std :: out_of_range("Invalid index.");
        }
        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
    }

    T get(int index) const override {
        if (index < 0 || index >= size) {
            throw std :: out_of_range("Invalid index.");
        }
        return data[index];
    }

    void set(int index, T value) override {
        if (index < 0 || index >= size) {
            throw std :: out_of_range("Invalid index.");
        }
        data[index] = value;
    }

    int size() const override {
        return size;
    }
};