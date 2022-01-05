#include "gtest/gtest.h"
#include "precompiler.h"
#include "../Hero.h"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

struct HeroTest : testing::Test
{
    Hero* hero;

    sf::Texture& texture_sheet;


    HeroTest()
    {
        hero = new Hero(200, 200, texture_sheet);
    }
    virtual ~HeroTest()
    {
        delete hero;
    }
};