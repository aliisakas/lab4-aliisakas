#pragma once

class MyVector {

private:
    int* data;
    size_t size;

public:
    MyVector(size_t n);
    ~MyVector();

    MyVector(const MyVector& other);
    MyVector& operator=(const MyVector& other);

    MyVector(MyVector&& other) noexcept;
    MyVector& operator=(MyVector&& other) noexcept;
};