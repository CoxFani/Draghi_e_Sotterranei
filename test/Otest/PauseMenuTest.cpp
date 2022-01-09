#include "gtest/gtest.h"

#include "../../PauseMenu.h"

TEST(PauseMenu, DefaultConstructor) {
    PauseMenu pauseMenu = PauseMenu();
    ASSERT_FALSE(pauseMenu.isButtonPressed("QUIT"));
}