#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "SparseVector.h"

SparseVector::SparseVector(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open file " << filename << std::endl;
        return;
    }

    int index;
    double value;
    char colon;
    while (file >> index >> colon >> value) {
        data[index] = value;
    }
}

SparseVector SparseVector::operator+(const SparseVector& other) const {
    SparseVector result;
    for (const auto& pair : data) {
        result.data[pair.first] += pair.second;
    }
    for (const auto& pair : other.data) {
        result.data[pair.first] += pair.second;
    }
    return result;
}

SparseVector SparseVector::operator-(const SparseVector& other) const {
    SparseVector result;
    for (const auto& pair : data) {
        result.data[pair.first] += pair.second;
    }
    for (const auto& pair : other.data) {
        result.data[pair.first] -= pair.second;
    }
    return result;
}

SparseVector SparseVector::operator-() const {
    SparseVector result(*this);
    for (auto& pair : result.data) {
        pair.second = -pair.second;
    }
    return result;
}

SparseVector& SparseVector::operator=(const SparseVector& other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const SparseVector& vec) {
    for (const auto& pair : vec.data) {
        os << pair.first << ":" << pair.second << " ";
    }
    return os;
}

double SparseVector::dot(const SparseVector& other) const {
    double result = 0.0;
    for (const auto& pair : data) {
        auto it = other.data.find(pair.first);
        if (it != other.data.end()) {
            result += pair.second * it->second;
        }
    }
    return result;
}
