template <typename T>
class BinaryTreeInterface {
public:
    virtual ~BinaryTree() {} 
    virtual	int height (BinaryTree<T>* root) const = 0;
    virtual	int countLeaf (BinaryTree<T>* root) const = 0;
    virtual	int sumNode (BinaryTree<T>* root) const = 0;
    virtual	bool isBST (BinaryTree<T>* root) const = 0;
    virtual	bool isFull (BinaryTree<T>* root)const  = 0;
    virtual	bool search (BinaryTree<T>* root, T k) const = 0;
    virtual	bool isLeaf () const = 0;
    virtual	void setLeft (BinaryTree<T>* b) = 0;
    virtual	void setRight (BinaryTree<T>* b) = 0;
    virtual	void printRange (BinaryTree<int>* root, int low, int high) const = 0;
    virtual	void printMultipleFive (BinaryTree<T>* root) const = 0;
    virtual	void setValue (const T& v) = 0;
    virtual T& getValue () const = 0;
    virtual	BinaryTree* getLeft () const = 0;
    virtual	BinaryTree* getRight () const = 0;
}