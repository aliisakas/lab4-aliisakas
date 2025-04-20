#include "myvector.hpp"
#include <algorithm>

MyVector::MyVector(size_t n) : size(n) {
    data = new int[n]{0};
}

MyVector::~MyVector() {
    delete[] data;
}



MyVector::MyVector(const MyVector& other) : size(other.size) {
    data = new int[size];
    std::copy(other.data, other.data + size, data);
}

MyVector& MyVector::operator=(const MyVector& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new int[size];
        std::copy(other.data, other.data + size, data);
    }
    return *this;
}



MyVector::MyVector(MyVector&& other) noexcept : data(other.data), size(other.size) {
    other.data = nullptr;
    other.size = 0;
}

MyVector& MyVector::operator=(MyVector&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }
    return *this;
}