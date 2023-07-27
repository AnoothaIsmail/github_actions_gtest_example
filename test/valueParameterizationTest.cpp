int divFun(int numerator, int denominator){
    if(denominator==0 || denominator<0 ){return 0;}
    return numerator/denominator;

}
TEST(DivFunTestSuite,HandleValidInputs){
int numerator = 10;
int denominator =5;
int expectedValue=2;
int actualValue=divFun(numerator, denominator);
ASSERT_EQ(actualValue, expectedValue);
}

TEST(DivFunTestSuite,HandleNegetiveDenominator){
int numerator = 10;
int denominator =-5;
int expectedValue=2;
int actualValue=divFun(numerator, denominator);
ASSERT_EQ(actualValue, expectedValue);
}