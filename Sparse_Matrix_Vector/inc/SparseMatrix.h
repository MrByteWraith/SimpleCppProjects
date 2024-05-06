#ifndef SPARSE_MATRIX_H
#define SPARSE_MATRIX_H

#include <iostream>
#include <map>
#include <string>

class SparseMatrix {
private:
    std::map<int, std::map<int, double>> data;

public:
    SparseMatrix() {}
    SparseMatrix(const std::string& filename);
    SparseMatrix operator+(const SparseMatrix& other) const;
    SparseMatrix operator-(const SparseMatrix& other) const;
    SparseMatrix operator-() const;
    SparseMatrix& operator=(const SparseMatrix& other);
    friend std::ostream& operator<<(std::ostream& os, const SparseMatrix& mat);
    SparseMatrix operator*(const SparseMatrix& other) const;
    SparseMatrix transpose() const;
};

#endif // SPARSEMATRIX_H
