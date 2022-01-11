//
// Created by gabriele on 10/01/22.
//

#include "gtest/gtest.h"
#include "precompiler.h"
#include "../Hero.h"
#include "../Game.h"

TEST(HeroTest, HeroIsDead){
    Hero hero = Hero(0.f, 0.f);
    EXPECT_FALSE(hero.isDead());
    hero.loseHP(4);
    EXPECT_FALSE(hero.isDead());
    hero.loseHP(2);
    EXPECT_TRUE(hero.isDead());
}

TEST(HeroTest, HeroAttacks){
    Hero hero = Hero(0.f, 0.f);
    EXPECT_FALSE(hero.getInitAttack());
    hero.setInitAttack(true);
    EXPECT_TRUE(hero.getInitAttack());
}

TEST(HeroTest, HeroCollision){
    Hero hero = Hero(50, 50);

}