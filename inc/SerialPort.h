#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <string>

class SerialPort {
public:
    SerialPort();
    bool initialize(const std::string &port);
    void start();  // Rename from open to start
    bool close();
    void set_dir(int dir);
    bool send(const std::string &data);
    void unlock();
    void rot(int angle);
private:
    std::string port;
    int fd; // File descriptor for the serial port
};

#endif // SERIALPORT_H
