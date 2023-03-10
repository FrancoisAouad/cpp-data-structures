#include "./queue.interface.h"
#include "stdexcept"

template <typename T>
class ListQueue : public QueueInterface<T> {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data, Node* next) : data(data), next(next) {}
    };
    Node* head;
    Node* tail;
public:
    ListQueue() : head(nullptr), tail(nullptr) {}
    ~ListQueue() {
        while (head) {
            Node* next = head->next;
            delete head;
            head = next;
        }
    }

    void enqueue(const T& val) override {
        if (!head) {
            head = tail = new Node(val, nullptr);
        } else {
            tail->next = new Node(val, nullptr);
            tail = tail->next;
        }
    }

    T dequeue() override {
        if (!head) {
            throw std :: underflow_error("Queue is empty");
        }
        T val = head->data;
        Node* oldHead = head;
        head = head->next;
        if (!head) {
            tail = nullptr;
        }
        delete oldHead;
        return val;
    }

    const T& front() const override {
        if (!head) {
            throw std :: underflow_error("Queue is empty");
        }
        return head->data;
    }

    bool isEmpty() const override {
        return head == nullptr;
    }

    bool isFull() const override {
        return false;
    }
};