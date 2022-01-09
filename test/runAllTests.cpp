#include "gtest/gtest.h"
#include "precompiler.h"
#include "../Hero.h"
#include "../Enemy.h"

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

