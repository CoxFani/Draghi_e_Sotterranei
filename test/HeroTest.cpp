//
// Created by gabriele on 10/01/22.
//

#include "gtest/gtest.h"
#include "precompiler.h"
#include "../Hero.h"

std::map<std::string, sf::Texture> textures;
Hero hero = Hero(0.f, 0.f, textures["HERO_SHEET"]);

TEST(HeroTest, HeroIsDead){
    EXPECT_FALSE(hero.isDead());
    hero.loseHP(4);
    EXPECT_FALSE(hero.isDead());
    hero.loseHP(2);
    EXPECT_TRUE(hero.isDead());
}

TEST(HeroTest, HeroAttacks){
    EXPECT_FALSE(hero.getInitAttack());
    hero.setInitAttack(true);
    EXPECT_TRUE(hero.getInitAttack());
}

TEST(HeroTest, HeroCollision){
    hero.setPosition(50.f, 50.f);
    auto sprite = nullptr;
    MovementComponent movementComponent = MovementComponent(reinterpret_cast<sf::Sprite &>(sprite), 140.f, 1500.f, 500.f);
    sf::Clock dtClock;
    float dt;
    dt = dtClock.getElapsedTime().asMilliseconds();
    hero.move(1.f, 0.f, dt);
    auto pos = nullptr;
    auto view = nullptr;
    hero.update(dt, reinterpret_cast<sf::Vector2f &>(pos), reinterpret_cast<sf::View&>(view));
    EXPECT_EQ(hero.getPosition().x, 51.f);
}
