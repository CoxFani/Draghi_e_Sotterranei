#include "gtest/gtest.h"
#include "precompiler.h"
#include "../Hero.h"
#include "../Enemy.h"
#include "../EnemySpawnerTile.h"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

struct HeroTest : testing::Test
{
    Hero* hero;

    HeroTest()
    {
        hero = new Hero(200, 200);
    }
    virtual ~HeroTest()
    {
        delete hero;
    }
};

struct EnemyTest : testing::Test
{
    Enemy* enemy;

    EnemyTest()
    {
        auto enemySpawnerTile = new EnemySpawnerTile(400, 400, 48, 1, 1, 60, 300);
        auto hero = new Hero(200, 200);
        enemy = new Enemy(400, 400, reinterpret_cast<EnemySpawnerTile &>(enemySpawnerTile),
                          reinterpret_cast<GameCharacter &>(hero));
    }
    virtual ~EnemyTest()
    {
        delete enemy;
    }
};

struct EnemySpawnerTileTest : testing::Test
{
    EnemySpawnerTile* enemySpawnerTile;

    EnemySpawnerTileTest()
    {
        enemySpawnerTile = new EnemySpawnerTile(400, 400, 48, 1, 1, 60, 300);
    }
    virtual ~EnemySpawnerTileTest()
    {
        delete enemySpawnerTile;
    }
};