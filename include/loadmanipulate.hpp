#include <opencv2/opencv.hpp>
#include <string>
#ifndef LOAD_MANIPULATE_H
#define LOAD_MANIPULATE_H

/**
 * @brief Namespace containing classes used for trying opencv functionality
 */
namespace cvtest {

/**
 * @brief Class providing functionality to load, save and blur images using
 * opencv functionality
 */
class LoadManipulateImage {
public:
    /**
     * @brief Default constructor. No functionality
     */
    LoadManipulateImage();
    /**
     * @brief Default destructor. No functionality
     */
    ~LoadManipulateImage();

    /**
     * @brief Loads an image from the file at the specified path
     * @param name The filename/path and filename of the imagefile to load
     */
    void load(std::string name);

    /**
     * @brief Applies a gaussian blur to the loaded image
     * Fails, if no image is provided
     */
    void blur();

    /**
     * @brief Saves an image to the file at the specified path
     * The file type to save as is extracted from the extension of the filename
     * specified
     * @param name The filename/path and filename to save the image to
     */
    void save(std::string name);

    /**
     * @brief Returns a size object specifying the dimensions of the loaded
     * image
     * @return A new instance of `cv::Size` with the resolution of the image
     * loaded
     */
    cv::Size getResolution();

    /**
     * @brief Calculates The Answer to the Ultimate Question of Life, The
     * Universe, and Everything
     * @return The Answer to the Ultimate Question of Life, The Universe, and
     * Everything
     */
    int32_t test();

private:
    /**
     * @return The number of pixels the loaded image is wide
     */
    uint32_t getWidth();

    /**
     * @return The number of pixels the loaded image is high
     */
    uint32_t getHeight();

    /**
     * @brief The image loaded
     */
    cv::Mat currentImg;
};
}  // namespace cvtest

#endif  // !LOAD_MANIPULATE_H