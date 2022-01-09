//
// Created by gabriele on 09/01/22.
//
/*
#include "gtest/gtest.h"
#include "precompiler.h"
#include "../Hero.h"
#include "../Enemy.h"

struct FollowTest : testing::Test
{
    Enemy* enemy;
    Hero* hero;

    EnemyTest()
    {
        auto enemySpawnerTile = new EnemySpawnerTile(300, 300, 48, 1, 1, 60, 1000);
        hero = new Hero(200, 200);
        enemy = new Enemy(300, 300, reinterpret_cast<EnemySpawnerTile &>(enemySpawnerTile),
                          reinterpret_cast<GameCharacter &>(hero));
    }
    virtual ~EnemyTest()
    {
        delete hero;
        delete enemy;
    }
};*/

