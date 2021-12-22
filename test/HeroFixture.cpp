#include "gtest/gtest.h"
#include "../precompiler.h"

#include "../Hero.h"
#include "../AttributeComponent.h"

class HeroSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        attributeComponent->hp = 0;
        hero->isDead();
    }

    Hero* hero;
    AttributeComponent* attributeComponent;
};


TEST_F(HeroSuite, TestDead) {
    ASSERT_TRUE(hero->isDead());
}

