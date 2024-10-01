#include "Camera.h"
Camera::Camera(const std::string &device) : device(device) {}

bool Camera::initialize() {
    
    cap.open(device);
    if (!cap.isOpened()) {
        std::cerr << "无法打开相机设备" << std::endl;
        return -1;
    }
    //cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('Y', 'U', 'Y', 'V'));
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 512);
    return cap.isOpened();
}

void Camera::open() {
    std::cout<<"open sucessed"<<std::endl;
}

void Camera::close() {
    cap.release();
}

cv::Mat Camera::getCurrentFrame() {
    
    cv::Mat frame;
    cap >> frame;  // 从相机获取一帧
    // 检查frame是否成功获取
    cv::Mat grayMat;
    cv::cvtColor(frame, grayMat, cv::COLOR_BGR2GRAY);
    if (!grayMat.empty()) {
        return grayMat;
    } 
}
