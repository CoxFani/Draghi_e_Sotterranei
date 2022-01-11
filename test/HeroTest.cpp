//
// Created by gabriele on 10/01/22.
//

#include "gtest/gtest.h"
#include "precompiler.h"
#include "../Hero.h"
#include "../RegularTile.h"

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
    sf::Sprite sprite;
    sprite.setPosition(0, 0);
    HitboxComponent hitbox = HitboxComponent(sprite, 7.f, 23.f, 20.f, 25.f);

    sf::Sprite shape;
    sf::Texture texture;
    sf::IntRect texture_r;
    texture_r.height = 32;
    texture_r.width = 32;
    texture_r.top = 0;
    texture_r.left = 0;
    RegularTile tile = RegularTile(0, 0, 0, 48.f, texture, texture_r, false);


    if(hitbox.intersect(static_cast<sf::FloatRect>(texture_r)) && tile.getCollision()){
        hero.stopVelocityX();
        hero.stopVelocityY();
    }

    EXPECT_TRUE(hero.isMovingX() && hero.isMovingY());

    tile.setCollision(true);

    if(hitbox.intersect(static_cast<sf::FloatRect>(texture_r)) && tile.getCollision()){
        hero.stopVelocityX();
        hero.stopVelocityY();
    }

    EXPECT_FALSE(hero.isMovingX() || hero.isMovingY());





}
