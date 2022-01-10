//
// Created by gabriele on 10/01/22.
//

#include "gtest/gtest.h"
#include "precompiler.h"
#include "../Hero.h"
#include "../Game.h"

TEST(HeroTests, HeroIsDead){
    Hero hero = Hero(0, 0);
    EXPECT_FALSE(hero.isDead());
    hero.loseHP(4);
    EXPECT_FALSE(hero.isDead());
    hero.loseHP(2);
    EXPECT_TRUE(hero.isDead());
}

TEST(HeroTests, HeroAttacks){
    Hero hero = Hero(0, 0);
    EXPECT_FALSE(hero.getInitAttack());
    hero.setInitAttack(true);
    EXPECT_TRUE(hero.getInitAttack());
    /*Game game = Game();
    sf::Clock dtClock;
    float dt;
    dt = dtClock.restart().asSeconds();
    hero.move(1, 1, dt);
    EXPECT_FALSE(hero.getInitAttack());*/
}