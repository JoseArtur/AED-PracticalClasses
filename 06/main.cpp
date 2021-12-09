#include "gtest/gtest.h"
#include "gmock/gmock.h"
class Douro {
public:
    Douro() {/*2*/}
    virtual ~Douro() {/*2out*/}
};
class Porto:public Douro{
public:
    Porto() {/*1in*/}
    virtual ~Porto() {/*1out*/}
};
int main(int argc, char* argv[]) {
   testing::InitGoogleTest(&argc, argv);
    std::cout << "AED 2021/2022 - Aula Pratica 6" << std::endl;
    return RUN_ALL_TESTS();

}
