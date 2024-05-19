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
    EXPECT_EQ(product.Operation(), "{Result of the ConcreteProduct1}");
}

class ProductMock2 : public ConcreteProduct2{
    public:
    MOCK_CONST_METHOD0(Operation, std::string());
};

//Second test

TEST(ProductMock2, Mock){
    ProductMock2 product;
    EXPECT_EQ(product.Operation(), "{Result of the ConcreteProduct2}");
}

class ConcreteCreatorMock : public ConcreteCreator1{
    public:
    MOCK_CONST_METHOD0(FactoryMethod, Product*());
};

//Third test

TEST(ConcreteCreatorMock, Mock){
    ConcreteCreatorMock creator;
    product = new ConcreteProduct1();
    EXPECT_EQ(creator.FactoryMethod(), product);
    delete product;
}
