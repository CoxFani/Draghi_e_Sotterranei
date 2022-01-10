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
}

TEST(HeroTests, HeroCollision){
    Game game = Game();
    Hero hero = Hero(50, 50);
    sf::Clock dtClock;
    float dt;
    dt = dtClock.getElapsedTime().asMilliseconds();
    hero.move(1, 0, dt);
    EXPECT_EQ(hero.getPosition().x, 51);
}