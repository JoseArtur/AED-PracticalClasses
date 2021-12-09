#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "funSearchProblem.h"
#include <vector>
using testing::Eq;

TEST(test, facingsun){
    EXPECT_EQ(3,FunSearchProblem::facingSun({2,3,1,2,4,1}));
    EXPECT_EQ(0,FunSearchProblem::facingSun({}));
    EXPECT_EQ(1,FunSearchProblem::facingSun({7}));
}

TEST(test, squareR){
 EXPECT_EQ(4,FunSearchProblem::squareR(18));
 EXPECT_EQ(7,FunSearchProblem::squareR(56));
 EXPECT_EQ(6,FunSearchProblem::squareR(45));



}

TEST(test, missingvalue){

}

TEST(test, minPages){

}
