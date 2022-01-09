//
// Created by gabriele on 09/01/22.
//

#include "gtest/gtest.h"
#include "precompiler.h"
#include "../Hero.h"
#include "../Enemy.h"

class EnemySuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        new EnemySpawnerTile(300, 300, 48, 1, 1, 60, 1000);
        new Hero(200, 200);
        new Enemy(300, 300, enemySpawnerTile, hero);
    }

    Enemy enemy;
    Hero hero;
    EnemySpawnerTile enemySpawnerTile;
};

