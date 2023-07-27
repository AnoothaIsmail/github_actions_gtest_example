#include "gtest/gtest.h"

class DivFunctionTestSuite:public testing::TestWithParam<std::tuple<int,int,int>> {
protected:
DivFunctionTestSuite(){}
~DivFunctionTestSuite(){}
}
int divFun(int numerator, int denominator){
    if(denominator==0 || denominator<0 ){return 0;}
    return numerator/denominator;

}
TEST_P(DivFunTestSuite,HandleValidInputs){
int numerator =std::get<0>(GetParam());
int denominator =std::get<1>(GetParam());
int expectedValue=std::get<2>(GetParam());
int actualValue=divFun(numerator, denominator);
ASSERT_EQ(actualValue, expectedValue);
}

INSTANTIATE_TEST_SUITE_P(DivFunTestSuiteParameterName, DivFunctionTestSuite,
 ::testing::values(
    std::make_tuple(10,5,2),
    std::make_tuple(10,0,0),
    std::make_tuple(10,-5,0))
 );

/*
TEST(DivFunTestSuite,HandleNegetiveDenominator){
int numerator =std::get<0>(GetParam());
int denominator =std::get<1>(GetParam());
int expectedValue=std::get<2>(GetParam());
int actualValue=divFun(numerator, denominator);
ASSERT_EQ(actualValue, expectedValue);
}*/