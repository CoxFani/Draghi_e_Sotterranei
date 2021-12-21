//
// Created by gabriele on 01/12/21.
//

#include "gtest/gtest.h"

#include "../Hero.h"

TEST(Hero, DefaultConstructor) {
    Hero h;
    ASSERT_EQ(0, h.getXPos());
    ASSERT_EQ(0, h.getYPos());
    ASSERT_FALSE(h.isFighting());
}


TEST(Hero, TestFightingMove) {
    Hero h;
    h.setFighting(true);
    ASSERT_TRUE(h.isFighting());
    h.move(1, 1);  // moving should disable fighting
    ASSERT_FALSE(h.isFighting());
}
