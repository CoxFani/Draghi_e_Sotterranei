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
    Enemy* enemy;

    EnemyTest()
    {
        auto enemySpawnerTile = new EnemySpawnerTile(300, 300, 48, 1, 1, 60, 1000);
        auto hero = new Hero(200, 200);
        enemy = new Enemy(300, 300, reinterpret_cast<EnemySpawnerTile &>(enemySpawnerTile),
                          reinterpret_cast<GameCharacter &>(hero));


    }
    virtual ~EnemyTest()
    {
        delete enemy;
    }
};

TEST_F(EnemyTest, EnemyAttacksHero){
    auto hero = new Hero(200, 200);
    EXPECT_LT(vectorDistance(enemy->getPosition(), hero->getPosition()), 200.f);
}

