#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "SparseMatrix.h"

SparseMatrix::SparseMatrix(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open file " << filename << std::endl;
        return;
    }

    int row, col;
    double value;
    char colon; 
    while (file >> row) {
        while (file >> col >> colon >> value) {
            data[row][col] = value;
            if (file.peek() == '\n') break; 
        }
    }
}


SparseMatrix SparseMatrix::operator+(const SparseMatrix& other) const {
    SparseMatrix result(*this); // Copy the current matrix
    for (const auto& row : other.data) {
        for (const auto& pair : row.second) {
            result.data[row.first][pair.first] += pair.second; // Add elements from the other matrix
        }
    }
    return result;
}

SparseMatrix SparseMatrix::operator-(const SparseMatrix& other) const {
    SparseMatrix result(*this); // Copy the current matrix
    for (const auto& row : other.data) {
        for (const auto& pair : row.second) {
            result.data[row.first][pair.first] -= pair.second; // Subtract elements from the other matrix
        }
    }
    return result;
}

SparseMatrix SparseMatrix::operator-() const {
    SparseMatrix result(*this); // Copy the current matrix
    for (auto& row : result.data) {
        for (auto& pair : row.second) {
            pair.second = -pair.second; // Negate elements of the matrix
        }
    }
    return result;
}

SparseMatrix& SparseMatrix::operator=(const SparseMatrix& other) {
    if (this != &other) {
        data = other.data; // Assign elements from the other matrix
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const SparseMatrix& mat) {
    for (const auto& row : mat.data) {
        os << row.first << " ";
        for (const auto& pair : row.second) {
            os << pair.first << ":" << pair.second << " ";
        }
        os << std::endl;
    }
    return os;
}

SparseMatrix SparseMatrix::operator*(const SparseMatrix& other) const {
    SparseMatrix result(*this); // Copy the current matrix
    for (const auto& row : data) {
        for (const auto& pair1 : row.second) {
            int row_index = pair1.first;
            double value1 = pair1.second;
            for (const auto& pair2 : other.data.at(row_index)) { // Use at() instead of []
                int col_index = pair2.first;
                double value2 = pair2.second;
                result.data[row_index][col_index] += value1 * value2; // Perform matrix multiplication
            }
        }
    }
    return result;
}

SparseMatrix SparseMatrix::transpose() const {
    SparseMatrix transposed;
    for (const auto& row : data) {
        for (const auto& pair : row.second) {
            transposed.data[pair.first][row.first] = pair.second;
        }
    }
    return transposed;
}