#include <iostream>
#include <omp.h>
#include "./matrix.interfaces.hpp"

class Matrix : public MatrixInterface {
private:
    int** data;
    int size;

public:
    Matrix(int size) : size(size) {
        data = new int*[size];
        for(int i=0; i<size; i++) {
            data[i] = new int[size];
        }
    }

    Matrix(const Matrix& other) : size(other.size) {
        data = new int*[size];
        for(int i=0; i<size; i++) {
            data[i] = new int[size];
            for(int j=0; j<size; j++) {
                data[i][j] = other.data[i][j];
            }
        }
    }

    ~Matrix() {
        for(int i=0; i<size; i++) {
            delete[] data[i];
        }
        delete[] data;
    }

    int getSize() const override {
        return size;
    }

    int& operator()(int row, int col) override {
        return data[row][col];
    }

    const int& operator()(int row, int col) const override {
        return data[row][col];
    }

    Matrix& operator=(const Matrix& other) {
        if(this != &other) {
            for(int i=0; i<size; i++) {
                delete[] data[i];
            }
            delete[] data;

            size = other.size;

            data = new int*[size];
            for(int i=0; i<size; i++) {
                data[i] = new int[size];
                for(int j=0; j<size; j++) {
                    data[i][j] = other.data[i][j];
                }
            }
        }
        return *this;
    }
};


class OmpMatrixMultiplier : public MatrixMultiplier {
public:
    void multiply(const MatrixInterface& matrix1, const MatrixInterface& matrix2, MatrixInterface& multMatrix, int num_threads) override {
        omp_set_num_threads(num_threads);
        #pragma omp parallel for collapse(2)
        for(int i=0; i<matrix1.getSize(); i++) {
            for(int j=0; j<matrix2.getSize(); j++) {
                multMatrix(i,j) = 0;
                for(int k=0; k<matrix1.getSize(); k++) {
                    multMatrix(i,j) += matrix1(i,k) * matrix2(k,j);
                }
            }
        }
    }
};
