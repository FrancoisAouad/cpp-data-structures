class QueueInterface {
public:
    virtual ~QueueInterface() {}
    virtual void enqueue(const T& value) = 0;
    virtual T dequeue() = 0;
    virtual const T& front() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool isFull() const = 0;
};