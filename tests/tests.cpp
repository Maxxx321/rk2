#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "product.h"
#include "creator.h"

class ProductMock1 : public ConcreteProduct1{
    public:
    MOCK_CONST_METHOD0(Operation, std::string());
};

//First test

TEST(ProductMock1, Mock){
    ProductMock1 product;
    EXPECT_CALL(product, Operation()).Times(1);
    product.Operation();

}

class ProductMock2 : public ConcreteProduct2{
    public:
    MOCK_CONST_METHOD0(Operation, std::string());
};

//Second test

TEST(ProductMock2, Mock){
    ProductMock2 product;
    EXPECT_CALL(product, Operation()).Times(1);
    product.Operation();
}

class ConcreteCreatorMock : public ConcreteCreator1{
    public:
    MOCK_CONST_METHOD0(FactoryMethod, Product*());
};

//Third test

TEST(ConcreteCreatorMock, Mock){
    ConcreteCreatorMock creator;
    EXPECT_CALL(creator, FactoryMethod()).Times(1);
    creator.FactoryMethod();
}
