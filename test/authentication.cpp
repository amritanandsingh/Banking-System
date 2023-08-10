#include <iostream>
#include <gtest/gtest.h>
#include "../header/authentication.hpp"

TEST(AddTest, PositiveNumbers) {
    authentication obj;
    EXPECT_EQ(1, obj.logIn("321", "321", "customer"));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
