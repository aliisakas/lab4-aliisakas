#pragma once

template<typename T, size_t N>
class MyArray {
private:
    T data[N];

public:
    T& operator[](size_t i) {
        return data[i];
    }

    const T& operator[](size_t i) const {
        return data[i];
    }

    size_t size() const {
        return N;
    }

    T& front() { return data[0]; }
    const T& front() const { return data[0]; }

    T& back() { return data[N - 1]; }
    const T& back() const { return data[N - 1]; }
};