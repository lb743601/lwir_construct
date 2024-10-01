#include "SerialPort.h"
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <iostream>

SerialPort::SerialPort() : fd(-1) {}  // 构造函数不再传入串口号

bool SerialPort::initialize(const std::string &port) {
    this->port = port;  // 在初始化时保存串口号
    fd = open(port.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd == -1) {
        std::cerr << "Error opening port: " << port << std::endl;
        return false;
    }

    // 设置串口参数
    struct termios options;
    tcgetattr(fd, &options); // 获取当前串口设置

    // 设置输入和输出波特率
    cfsetispeed(&options, B115200);  // 输入波特率
    cfsetospeed(&options, B115200);  // 输出波特率

    // 设置本地模式和启用接收
    options.c_cflag |= (CLOCAL | CREAD);

    // 设置数据位 8 位，清除停止位和校验位
    options.c_cflag &= ~CSIZE; // 清除数据位字段
    options.c_cflag |= CS8;    // 设置 8 数据位
    options.c_cflag &= ~PARENB; // 无校验位
    options.c_cflag &= ~CSTOPB; // 1 个停止位

    // 设置为原始模式，禁用控制字符
    // 应用设置
    tcsetattr(fd, TCSANOW, &options);
    set_dir(1);
    return true;
}
void SerialPort::start() {
    // Any additional setup if needed
}

bool SerialPort::close() {
    if (fd != -1) {
        ::close(fd); // Use ::close to call global close function
        fd = -1;
        return true;
    }
    return false;
}

bool SerialPort::send(const std::string &data) {
    if (fd != -1) {
        std::string utf8Data = data+"\n" ;
        write(fd, utf8Data.c_str(), utf8Data.size());
        return true;
    }
    else return false;
}
void SerialPort::set_dir(int dir)
{   std::string command;
    if(dir == 1) command= "set_dir(1)";
    else command = "set_dir(0)";
    send(command);
}
void SerialPort::unlock()
{
    std::string command;
    command= "stop_pwm()";
    send(command);
}
void SerialPort::rot(int angle)
{
    int pwm_num=12800*angle/360;
    std::string command = "start_pwm(72,200," + std::to_string(pwm_num) + ")";
    send(command);
}