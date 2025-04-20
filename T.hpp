#pragma once
#include <sstream>

template <typename T>
void mySwap(T& a, T& b) {
    T c = std::move(a);
    a = std::move(b);
    b = std::move(c);
}

template<typename Container>
std::string container_to_string(const Container& cont) {
    std::ostringstream oss;
    for (const auto& elem : cont) {
        oss << elem << " ";
    }
    return oss.str();
}