//
// Created by András on 2017. 10. 21..
//
#include <gtest/gtest.h>
#include "../include/Dustbin.h"
#include "../include/Dustbin9000.h"
#include "../include/DustbinContentError.h"
#include "../include/DustbinIsFull.h"
#include "../include/BottleCapException.h"

class ClassDeclaration : public testing::Test {
    public:
        Dustbin dustbin = Dustbin("red");
        Dustbin9000 d9k = Dustbin9000("green");

        std::unique_ptr<Garbage> overweightGarbage = std::unique_ptr<Garbage>(new Garbage("overweight garbage", 500));
        std::unique_ptr<Garbage> tinyGarbage = std::unique_ptr<Garbage>(new Garbage("tiny garbage", 5));
        std::unique_ptr<Garbage> houseWaste = std::unique_ptr<Garbage>(new Garbage("house garbage", 10));
        std::unique_ptr<PaperGarbage> paperGarbage = std::unique_ptr<PaperGarbage>(new PaperGarbage("some paper", 10, false));
        std::unique_ptr<PlasticGarbage> plasticGarbage = std::unique_ptr<PlasticGarbage>(new PlasticGarbage("some plastic", 2, false));
        std::unique_ptr<MetalGarbage> metalGarbage = std::unique_ptr<MetalGarbage>(new MetalGarbage("some metal garbage", 10));
        std::unique_ptr<BottleCap> pinkBottleCap = std::unique_ptr<BottleCap>(new BottleCap("pink bottle cap", 1, "pink"));
        std::unique_ptr<BottleCap> nonPintBottleCap = std::unique_ptr<BottleCap>(new BottleCap("blue bottle cap", 1, "blue"));
};

TEST_F(ClassDeclaration, throwOutGarbageTest) {
    dustbin.throwOutGarbage(std::move(houseWaste));
    for(auto& garbage: dustbin.getHouseWasteContent()) {
        ASSERT_EQ(garbage->getName(), "house garbage");
    }
}

TEST_F(ClassDeclaration, throwOutPaperGarbageTest) {
    paperGarbage->squeeze();
    dustbin.throwOutPaperGarbage(std::move(paperGarbage));
    for(auto& garbage: dustbin.getHouseWasteContent()) {
        ASSERT_EQ(garbage->getName(), "some paper");
    }
}

TEST_F(ClassDeclaration, throwOutPlasticGarbageTest) {
    plasticGarbage->clean();
    dustbin.throwOutPlasticGarbage(std::move(plasticGarbage));
    for(auto& garbage: dustbin.getHouseWasteContent()) {
        ASSERT_EQ(garbage->getName(), "some plastic");
    }
}

TEST_F(ClassDeclaration, paperGarbageIsNotSqueezedTest) {
    ASSERT_FALSE(paperGarbage->getIsSqueezed());
}

TEST_F(ClassDeclaration, paperGarbageSqueezingTest) {
    paperGarbage->squeeze();
    ASSERT_TRUE(paperGarbage->getIsSqueezed());
}

TEST_F(ClassDeclaration, plasticGarbageIsNotCleanTest) {
    ASSERT_FALSE(plasticGarbage->getIsClean());
}

TEST_F(ClassDeclaration, plasticGarbageCleaningTest) {
    plasticGarbage->clean();
    ASSERT_TRUE(plasticGarbage->getIsClean());
}

TEST_F(ClassDeclaration, dustbinContentErrorTest) {
    ASSERT_THROW(dustbin.throwOutPaperGarbage(std::move(paperGarbage)), DustbinContentError);
    ASSERT_THROW(dustbin.throwOutPlasticGarbage(std::move(plasticGarbage)), DustbinContentError);
}

TEST_F(ClassDeclaration, dustbinIsFullByWeightTest) {
    ASSERT_THROW(dustbin.throwOutGarbage(std::move(overweightGarbage)), DustbinIsFull);
}

TEST_F(ClassDeclaration, dustbinFullByAmountTest) {
    plasticGarbage->clean();
    paperGarbage->squeeze();
    ASSERT_NO_THROW(dustbin.throwOutGarbage(std::move(houseWaste)));
    ASSERT_NO_THROW(dustbin.throwOutPlasticGarbage(std::move(plasticGarbage)));
    ASSERT_NO_THROW(dustbin.throwOutPaperGarbage(std::move(paperGarbage)));
    // dustbin content cap is 3, the 4th piece of garbage should throw an exception.
    ASSERT_THROW(dustbin.throwOutGarbage(std::move(tinyGarbage)), DustbinIsFull);
}

TEST_F(ClassDeclaration, dustbinEmptyTest) {
    plasticGarbage->clean();
    paperGarbage->squeeze();
    dustbin.throwOutGarbage(std::move(tinyGarbage));
    dustbin.throwOutGarbage(std::move(houseWaste));
    dustbin.throwOutPlasticGarbage(std::move(plasticGarbage));
    dustbin.emptyContents(); //empty to avoid overflow
    dustbin.throwOutPaperGarbage(std::move(paperGarbage));
    dustbin.emptyContents();
    ASSERT_EQ(dustbin.getCurrentGarbageAmount(), 0);
    ASSERT_EQ(dustbin.getCurrentWeight(), 0);
    ASSERT_TRUE(dustbin.getHouseWasteContent().empty());
    ASSERT_TRUE(dustbin.getPlasticContent().empty());
    ASSERT_TRUE(dustbin.getPaperContent().empty());
}

TEST_F(ClassDeclaration, d9kThrowOutMetalGarbageTest) {
    d9k.throwOutMetalGarbage(std::move(metalGarbage));
    for(auto& garbage: d9k.getMetalContent()) {
        ASSERT_EQ(garbage->getName(), "some metal garbage");
    }
}

TEST_F(ClassDeclaration, d9kThrowOutBottleCapTest) {
    ASSERT_NO_THROW(d9k.throwOutBottleCap(std::move(pinkBottleCap)));
    for(auto& bottleCap: d9k.getBottleCapContent()) {
        ASSERT_EQ(bottleCap->getName(), "pink bottle cap");
    }
    ASSERT_THROW(d9k.throwOutBottleCap(std::move(nonPintBottleCap)), BottleCapException);

}

TEST_F(ClassDeclaration, d9kEmptyWithExtraContentsTest) {
    plasticGarbage->clean();
    paperGarbage->squeeze();
    d9k.throwOutGarbage(std::move(tinyGarbage));
    d9k.throwOutGarbage(std::move(houseWaste));
    d9k.throwOutPlasticGarbage(std::move(plasticGarbage));
    d9k.emptyContents(); //empty to avoid overflow
    d9k.throwOutPaperGarbage(std::move(paperGarbage));
    d9k.throwOutMetalGarbage(std::move(metalGarbage));
    d9k.throwOutBottleCap(std::move(pinkBottleCap));
    d9k.emptyContents();
    ASSERT_EQ(dustbin.getCurrentGarbageAmount(), 0);
    ASSERT_EQ(dustbin.getCurrentWeight(), 0);
    ASSERT_TRUE(dustbin.getHouseWasteContent().empty());
    ASSERT_TRUE(dustbin.getPlasticContent().empty());
    ASSERT_TRUE(dustbin.getPaperContent().empty());
}
