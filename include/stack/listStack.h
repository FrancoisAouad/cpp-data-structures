#include "./listStack.h"
#include "stdexcept"

template <typename T>
class ListStack : public StackInterface<T> {
private:
    struct Node {
        T data;
        Node* next;
        Node(T data, Node* next) : data(data), next(next) {}
    };
    Node* head;

public:
    ListStack() : head(nullptr) {}
    ~ListStack() {
        while (head) {
            Node* next = head->next;
            delete head;
            head = next;
        }
    }

    void push(T val) {
        head = new Node(val, head);
    }

    T pop() {
        if (!head) {
            throw std::underflow_error("Stack is empty.");
        }
        T val = head->data;
        Node* oldHead = head;
        head = head->next;
        delete oldHead;
        return val;
    }

    T top() const {
        if (!head) {
            throw std::underflow_error("Stack is empty.");
        }
        return head->data;
    }

    bool isEmpty() const {
        return head == nullptr;
    }
};
