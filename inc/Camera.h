#ifndef CAMERA_H
#define CAMERA_H

#include <opencv2/opencv.hpp>

class Camera {
public:
    Camera(const std::string &device);
    bool initialize();
    void open();
    void close();
    cv::Mat getCurrentFrame();

private:
    std::string device;
    cv::VideoCapture cap;
};

#endif // CAMERA_H
