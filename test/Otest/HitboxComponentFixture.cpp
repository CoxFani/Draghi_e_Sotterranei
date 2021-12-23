#include "gtest/gtest.h"

#include "../../HitboxComponent.h"


class HitboxComponentSuite : public ::testing::Test {

protected:
    virtual void SetUp() {

    }

    HitboxComponent hitbox;
};


TEST_F(HitboxComponentSuite, TestMove) {
    //hitbox.intersect();

}

