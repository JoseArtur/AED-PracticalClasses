#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <vector>
#include <iostream>
using namespace std;


template <class T>
class MyVector {
    vector<T> v;
public:
    MyVector();
    ~MyVector();
    T max() const;
    bool hasDuplicates(void) const;
};




int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    std::cout << "AED 2021/2022 - Aula Pratica 2" << std::endl;
    return RUN_ALL_TESTS();;
}