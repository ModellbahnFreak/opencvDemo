#include <iostream>
#include <opencv2/opencv.hpp>

//using namespace cv;
/**
 * @brief Entry point of the executable
 * @param argc Number of command line arguments passed
 * @param argv List of command line arguments
 * @return Exit code of the application. 0 if Program ran successfully; other value else
*/
int main(int argc, char** argv) {
	cv::Mat emptyImg(100, 100, CV_8UC3, cv::Scalar(255, 0, 0));
	cv::imshow("An image", emptyImg);
	cv::waitKey();

	cv::Mat loadedImage;
	loadedImage = cv::imread("./opencv.png");
	std::cout << "Image loaded" << std::endl;
	
	cv::imshow("An image", loadedImage);
	cv::waitKey();
	std::cout << "Key pressed" << std::endl;

	cv::Mat cropped(loadedImage, cv::Rect(150, 150, 100, 100));
	cv::imshow("An image", cropped);
	cv::waitKey();

	return 0;
}