#include "gtest/gtest.h"

#include "../Hero.h"


class HeroSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        h.setXPos(10);
        h.setYPos(10);
        h.setFighting(true);
    }

    Hero h;
};


TEST_F(HeroSuite, TestMove) {
    h.move(12, 14);

    ASSERT_EQ(22, h.getXPos());
    ASSERT_EQ(24, h.getYPos());
}

