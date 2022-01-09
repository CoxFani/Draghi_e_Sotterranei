#include "gtest/gtest.h"

#include "../../PauseMenu.h"

class HeroSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        attributeComponent.hp = 0;
        hero.isDead();
    }

    PauseMenu pauseMenu;
};


TEST_F(PauseMenu, TestTypeMenu) {
    PauseMenu pauseMenu;
    ASSERT_TRUE(pauseMenu);
}

