#include "stdexcept"
#include "./list.interface.h"

template <typename T>
class LinkedList : public ListInterface<T> {
private:
    struct Node {
        T data;
        Node* next;
        Node(T data, Node* next) : data(data), next(next) {}
    };
    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    ~LinkedList() {
        while (head) {
            Node* next = head->next;
            delete head;
            head = next;
        }
    }

    void add(T value) override {
        if (!head) {
            head = new Node(value, nullptr);
        } else {
            Node* curr = head;
            while (curr->next) {
                curr = curr->next;
            }
            curr->next = new Node(value, nullptr);
        }
        ++size;
    }

    void remove(int index) override {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Invalid index.");
        }
        if (index == 0) {
            Node* oldHead = head;
            head = head->next;
            delete oldHead;
        } else {
            Node* curr = head;
            for (int i = 0; i < index - 1; ++i) {
                curr = curr->next;
            }
            Node* nodeToRemove = curr->next;
            curr->next = nodeToRemove->next;
            delete nodeToRemove;
        }
        --size;
    }

   const T get(int index) const override {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Invalid index.");
        }
        return data[index];
    }

    int size() const {
        return size;
    }
};