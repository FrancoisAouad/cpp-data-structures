class MatrixInterface {
public:
    virtual int getSize() const = 0;
    virtual int& operator()(int row, int col) = 0;
    virtual const int& operator()(int row, int col) const = 0;
    virtual ~MatrixInterface() {}
};


class MatrixMultiplier {
public:
    virtual void multiply(const MatrixInterface& matrix1, const MatrixInterface& matrix2, MatrixInterface& multMatrix, int num_threads) = 0;
    virtual ~MatrixMultiplier() {}
};


