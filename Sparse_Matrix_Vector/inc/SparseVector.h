#ifndef SPARSE_VECTOR_H
#define SPARSE_VECTOR_H

#include <iostream>
#include <map>
#include <string>

class SparseVector {
private:
    std::map<int, double> data;

public:
    SparseVector() {}
    SparseVector(const std::string& filename);
    //SparseVector& operator+=(const SparseVector& other);
    SparseVector operator+(const SparseVector& other) const;
    SparseVector operator-(const SparseVector& other) const;
    SparseVector operator-() const;
    SparseVector& operator=(const SparseVector& other);
    friend std::ostream& operator<<(std::ostream& os, const SparseVector& vec);
    double dot(const SparseVector& other) const;
};

#endif // SPARSEVECTOR_H
