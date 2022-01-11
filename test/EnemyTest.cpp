//
// Created by gabriele on 05/01/22.
//

#include "gtest/gtest.h"
#include "precompiler.h"
#include "../Hero.h"
#include "../Enemy.h"

TEST(EnemyTest, EnemyFollowsHero){
    EnemySpawnerTile enemySpawnerTile = EnemySpawnerTile(300.f, 300.f, 48.f, 1, 1, 60, 1000);
    Hero hero = Hero(200.f, 200.f);
    Enemy enemy = Enemy(300.f, 300.f, enemySpawnerTile, hero);
    EXPECT_LT(vectorDistance(enemy.getPosition(), hero.getPosition()), 200.f);
    AttackStrategy attackStrategy = AttackStrategy(enemy, hero);
    EXPECT_TRUE(attackStrategy.isMoving());
}

TEST(EnemyTest, EnemyNotFollowsHero){
    EnemySpawnerTile enemySpawnerTile = EnemySpawnerTile(300.f, 300.f, 48.f, 1, 1, 60, 1000);
    Hero hero = Hero(700.f, 200.f);
    Enemy enemy = Enemy(300.f, 300.f, enemySpawnerTile, hero);
    EXPECT_GT(vectorDistance(enemy.getPosition(), hero.getPosition()), 200.f);
    AttackStrategy attackStrategy = AttackStrategy(enemy, hero);
    EXPECT_FALSE(attackStrategy.isMoving());
}

TEST(EnemyTest, EnemyIsDead){
    EnemySpawnerTile enemySpawnerTile = EnemySpawnerTile(300.f, 300.f, 48.f, 1, 1, 60, 1000);
    Hero hero = Hero(200.f, 200.f);
    Enemy enemy = Enemy(300.f, 300.f, enemySpawnerTile, hero);
    EXPECT_FALSE(enemy.isDead());
    enemy.loseHP(4);
    EXPECT_FALSE(enemy.isDead());
    enemy.loseHP(2);
    EXPECT_TRUE(enemy.isDead());
}


