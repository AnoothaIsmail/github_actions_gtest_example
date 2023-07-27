#include <gtest/gtest.h>
using testing::Types;

class ITempSensor{
    public:
    virtual int getOutsideTemp()=0;
};
class ModelATempSensor:public ITempSensor{
    public:
    int getOutsideTemp() {return 23;}
};
class ModelBTempSensor{
    public:
    int getOutsideTemp() {return 23;}
};
class AutoTempRegulator{
    ITempSensor* tempSensorPtr;
    public:
    AutoTempRegulator(ITempSensor* address):tempSensorPtr(address) {}
    void regulateTemp() {
        this->tempSensorPtr->getOutsideTemp();
    }
};


template <typename T> //THIS S CALLED FACTORY FUNCTION
ITempSensor* createObject();
template <>
ITempSensor* createObject<ModelATempSensor>() { return new ModelATempSensor(); }
template <>
ITempSensor* createObject<ModelBTempSensor>() { return new ModelBTempSensor(); }

template <typename T>
class TempSensorFixture:public testing::Test{
    protected:
    TempSensorFixture():objUnderTest{createObject<T>()}{}  //type parameterization -data type to be considered for fixture -
    //Arrange 
    ITempSensor* objUnderTest;

};

typedef Types<ModelATempSensor,ModelBTempSensor> Implementations;

TYPED_TEST_SUITE(TempSensorFixture, Implementations) {
TYPED_TEST(TempSensorFixture,GetTempTest){
    ASSERT_EQ(objUnderTest.getOutsideTemp(),23)
}
}
/*
class ModalATempSensorFixture:public testing::Test{
    protected:
    //Arrange 
    ModalATempSensor objUnderTest;

}

TEST_F(ModalATempSensorFixture,GetTempTest) {
  ASSERT_EQ(objUnderTest.getOutsideTemp(), 23);
}

class ModalBTempSensorFixture:public testing::Test{
    protected:
    //Arrange 
    ModalBTempSensor objUnderTest;

}       

TEST_F(ModalBTempSensorFixture,GetTempTest) {
  ASSERT_EQ(objUnderTest.getOutsideTemp(), 23);
} */