#include<iostream>
#include <gtest/gtest.h>
#include "../header/validation.hpp"
using namespace std;
TEST(ValidationTest, ValidWordTest) {
    validation obj;
    EXPECT_TRUE(obj.isWord("amrit"));
}

TEST(ValidationTest, InvalidWordTest) {
    validation obj;
    EXPECT_FALSE(obj.isWord("amr*it"));
}

// Add more test cases as needed
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
