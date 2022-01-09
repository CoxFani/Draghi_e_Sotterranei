//
// Created by gabriele on 05/01/22.
//

#include "gtest/gtest.h"
#include "precompiler.h"
#include "../Hero.h"
#include "../Enemy.h"

TEST(FollowTest, EnemyAttacksHero){
    EnemySpawnerTile enemySpawnerTile = EnemySpawnerTile(300, 300, 48, 1, 1, 60, 1000);
    Hero hero = Hero(200, 200);
    Enemy enemy = Enemy(300, 300, enemySpawnerTile, hero);
    EXPECT_LT(vectorDistance(enemy.getPosition(), hero.getPosition()), 200.f);
}