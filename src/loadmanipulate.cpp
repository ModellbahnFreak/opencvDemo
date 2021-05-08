/**
 * @file
 * Source file containing the implementation of the cvtest::LoadManipulateImage
 * class
 */
#include "../include/loadmanipulate.hpp"
#include <opencv2/opencv.hpp>

using namespace cvtest;

LoadManipulateImage::LoadManipulateImage() {}

LoadManipulateImage::~LoadManipulateImage() {}

void LoadManipulateImage::load(std::string name) {
    this->currentImg = cv::imread(name);
}

void LoadManipulateImage::blur() {
    cv::GaussianBlur(currentImg, currentImg, cv::Size(21, 21), 21);
}

void LoadManipulateImage::save(std::string name) {
    cv::imwrite(name, currentImg);
}

uint32_t LoadManipulateImage::getWidth() {
    return currentImg.cols;
}

uint32_t LoadManipulateImage::getHeight() {
    return currentImg.rows;
}

cv::Size LoadManipulateImage::getResolution() {
    return cv::Size(getWidth(), getHeight());
}

int32_t LoadManipulateImage::test() {
    return 42;
}
