/**
 * @file
 * A testsuite consisting of basic arithmetic tests to show how the framework
 * works
 * @author GR
 */
#include <gtest/gtest.h>

/**
 * @brief A generic test to check if testing is working
 */
TEST(ArithmeticTest, TestAdd) {
    ASSERT_EQ(2, 1 + 1);
}
