#include "gtest/gtest.h"

#include "../PauseMenu.h"

TEST(PauseMenu, DefaultConstructor) {
    PauseMenu* pauseMenu (new PauseMenu());
    ASSERT_FALSE(pauseMenu->isButtonPressed("QUIT"));
}