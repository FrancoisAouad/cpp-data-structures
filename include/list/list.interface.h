template <typename T>
class ListInterface {
public:
    virtual ~ListInterface() {}
    virtual void add(T value) = 0;
    virtual void remove(int index) = 0;
    virtual T get(int index) const = 0;
    virtual void set(int index, T value) = 0;
    virtual int size() const = 0;
};