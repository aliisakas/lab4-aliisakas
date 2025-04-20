#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <sstream>
#include "myvector.hpp"
#include "T.hpp"
#include "myarray.hpp"

int main() {

    using namespace std::chrono;

    // 1) Move семантика
    MyVector vec1(1000000);

    auto startCopy = high_resolution_clock::now();
    MyVector vec2 = vec1;
    auto endCopy = high_resolution_clock::now();

    std::cout << "Время копирования: " << duration_cast<milliseconds>(endCopy - startCopy).count() << " ms\n";
   
    auto startMove = high_resolution_clock::now();
    MyVector vec3 = std::move(vec1);
    auto endMove = high_resolution_clock::now();

    std::cout << "Время перемещения: " << duration_cast<milliseconds>(endMove - startMove).count() << " ms\n";


    // 2.1) Шаблоны функций, MySwap
    std::string s1 = "string #1", s2 = "string #2";
    mySwap(s1, s2);
    std::cout << s1 << " " << s2 << std::endl;

    int a = 1, b = 2;
    mySwap(a, b);
    std::cout << a << " " << b << std::endl;


    // 2.2) Шаблоны функций, Контейнер в строку
    std::vector<int> vector1 = {1, 2, 3};
    std::list<std::string> list1 = {"a", "b", "c"};
    std::set<double> set1 = {1.5, 2.1, 3.5};

    std::cout << container_to_string(vector1) << std::endl;
    std::cout << container_to_string(list1) << std::endl;
    std::cout << container_to_string(set1) << std::endl;


    // 3) Шаблоны классов, MyArray
    MyArray<int, 5> arr1;
    for (int i = 0; i < arr1.size(); ++i)
        arr1[i] = i * 5;

    for (int i = 0; i < arr1.size(); ++i)
        std::cout << arr1[i] << " ";
    std::cout << std::endl;

    MyArray<std::string, 3> arr2;
    arr2[0] = "one";
    arr2[1] = "two";
    arr2[2] = "three";

    for (int i = 0; i < arr2.size(); ++i)
        std::cout << arr2[i] << " ";
    std::cout << std::endl;

    std::cout << "первый элемент: " << arr2.front() << ", последний элемент: " << arr2.back() << std::endl;

    return 0;
}