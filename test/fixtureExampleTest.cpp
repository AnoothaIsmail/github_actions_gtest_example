

class C{};
class B{
    C* ptr;
    public:
    B(C* addressOfObject) : ptr(addressOfObject) { //B depends on C pointer

    }
};
class A{
    B* ptr;
    public:
    A(B* addressOfObject) : ptr(addressOfObject) {//A depends on C pointer

    }
    bool operation(){
        return true;
    }
};



TEST(TestFixtureTestSuite, OperationsTrueTest){
    //Arrange
    C cObj;
    B bObj(&cObj);
    A aObj(&bObj);
    //Act and Assert
    ASSERT_FALSE(obj.operation());

}

TEST(TestFixtureTestSuite, OperationsFalseTest){
    //Arrange
    C cObj;
    B bObj(&cObj);
    A aObj(&bObj);
    //Act and Assert
    ASSERT_TRUE(obj.operation());

}