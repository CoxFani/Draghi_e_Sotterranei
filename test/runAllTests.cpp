#include "gtest/gtest.h"
#include "precompiler.h"
#include "../Hero.h"
#include "../Enemy.h"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

struct EnemyTest : testing::Test
{
    Enemy& enemy;
    Hero& hero;
    EnemySpawnerTile& enemySpawnerTile;

    EnemyTest(Enemy &enemy, EnemySpawnerTile &enemySpawnerTile, Hero &hero)
            : enemy(enemy), enemySpawnerTile(enemySpawnerTile), hero(hero) {
        new EnemySpawnerTile(300, 300, 48, 1, 1, 60, 1000);
        new Hero(200, 200);
        new Enemy(300, 300, enemySpawnerTile, hero);
    }
};

TEST_F(EnemyTest, EnemyAttacksHero){
    EXPECT_LT(vectorDistance(enemy.getPosition(), hero.getPosition()), 200.f);
}

