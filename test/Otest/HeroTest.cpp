#include "gtest/gtest.h"

#include "../../Hero.h"

TEST(Hero, DefaultConstructor) {
    Hero hero;
    ASSERT_TRUE(hero.getInitAttack());
    ASSERT_FALSE(hero.isDead());
}

TEST(Hero, TestDamageTimer) {
    Hero hero;
    hero.getDamageTimer();
    ASSERT_FALSE(hero.getDamageTimer());
}
