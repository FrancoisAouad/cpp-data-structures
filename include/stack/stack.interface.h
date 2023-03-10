template <typename T>
class StackInterface {
public:
    virtual ~StackInterface() {}
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
    virtual void push(T value) = 0;
    virtual T pop() = 0;
    virtual T top() const = 0;
};