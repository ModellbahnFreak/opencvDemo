/**
 * @file
 * Testsuite checking the functioality of the `cvtest::LoadManipulateImage`
 * class
 * @author GR
 */

#include <gtest/gtest.h>
#include "../include/loadmanipulate.hpp"

/**
 * @brief Tests if the loading of images runs without exceptions
 */
TEST(LoadManipulateTest, TestLoad) {
    cvtest::LoadManipulateImage loader;
    ASSERT_NO_THROW(loader.load("./opencv.png"));
}

/**
 * @brief Tests if the getResolution query of the loader is working correctily
 */
TEST(LoadManipulateTest, TestSize) {
    cvtest::LoadManipulateImage loader;
    loader.load("./opencv.png");
    cv::Size imgSize;
    ASSERT_NO_THROW(imgSize = loader.getResolution());
    ASSERT_EQ(imgSize.width, 600) << "Image width is wrong";
    ASSERT_EQ(imgSize.height, 600) << "Image height is wrong";
}

/**
 * @brief Tests if an image can be saved and reopened using a new instance
 */
TEST(LoadManipulateTest, TestSaving) {
    cvtest::LoadManipulateImage loader;
    loader.load("./opencv.png");
    ASSERT_NO_THROW(loader.save("./opencv_new.png"));
    cvtest::LoadManipulateImage checker;
    checker.load("./opencv_new.png");
    ASSERT_NO_THROW(checker.getResolution());
}