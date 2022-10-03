#include "SerialPort.h"
#include <errno.h>
#include <fcntl.h>
#include <linux/serial.h>
#include <sys/ioctl.h>
#include <sys/param.h>
#include <termios.h>
#include <unistd.h>
#include <cstring>

timespec timespec_from_ms(const uint32_t millis)
{
    timespec time;
    time.tv_sec = millis / 1e3;
    time.tv_nsec = (millis - (time.tv_sec * 1e3)) * 1e6;
    return time;
}

SerialPort::SerialPort() : is_running_(false) {}
SerialPort::~SerialPort() { Close(); }

bool SerialPort::Start(const std::string& device, unsigned long baudrate)
{
    if (!Open(device))
    {
        return false;
    }

    if (!Setup(baudrate))
    {
        return false;
    }

    std::cout << "Starting.";
    is_running_ = true;
    thread_ = std::thread(&SerialPort::Run, this);
    std::cout << "Started.";
    return true;
}

void SerialPort::Stop()
{
    if (!is_running_) return;
    std::cout << "Stopping.";

    is_running_ = false;
    if (thread_.joinable())
    {
        thread_.join();
    }

    std::cout << "Stopped.";
}

void SerialPort::Run()
{
    char buf[4096];

    while (is_running_)
    {
        uint32_t timeout = 5000;
        // Wait for the device to be readable, and then attempt to read.
        if (WaitReadable(timeout))
        {
            ssize_t bytes_read = read(fd_, buf, sizeof(buf));
            if (bytes_read < 1)
            {
                std::cout
                    << "device reports readiness to read but returned no data (device disconnected?)";
                return;
            }

            if (read_callback_ != nullptr)
            {
                read_callback_(buf, static_cast<std::size_t>(bytes_read));
            }
        }
    }
}

bool SerialPort::Open(const std::string& device)
{
    if (device.empty())
    {
        std::cout << "Empty port is invalid.";
        return false;
    }

    fd_ = open(device.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
    if (fd_ == -1)
    {
        std::cout << "Unable to open the port";
        return false;
    }

    return true;
}

void SerialPort::Close()
{
    if (fd_ != -1)
    {
        int ret = ::close(fd_);
        if (ret == 0)
        {
            fd_ = -1;
        }
        else
        {
            std::cout << "Unable to close the port.";
            return;
        }
    }
}

bool SerialPort::Setup(unsigned long baudrate, ByteSize bytesize, StopBits stopbits, Parity parity,
                       FlowControl flowcontrol)
{
    if (fd_ == -1)
    {
        std::cout << "Invalid file descriptor, is the serial port open?";
        return false;
    }

    struct termios options;  // The options for the file descriptor
    if (tcgetattr(fd_, &options) == -1)
    {
        std::cout << "tcgetattr error";
        return false;
    }

    // set up raw mode / no echo / binary
    options.c_cflag |= (tcflag_t)(CLOCAL | CREAD);
    options.c_lflag &= (tcflag_t) ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ISIG | IEXTEN);  //|ECHOPRT

    options.c_oflag &= (tcflag_t) ~(OPOST);
    options.c_iflag &= (tcflag_t) ~(INLCR | IGNCR | ICRNL | IGNBRK);

    options.c_iflag &= (tcflag_t)~IUCLC;
    options.c_iflag &= (tcflag_t)~PARMRK;

    // 串口波特率设置
    bool custom_baud = false;
    speed_t baud;
    switch (baudrate)
    {
        case 0:
            baud = B0;
            break;
        case 50:
            baud = B50;
            break;
        case 75:
            baud = B75;
            break;
        case 110:
            baud = B110;
            break;
        case 134:
            baud = B134;
            break;
        case 150:
            baud = B150;
            break;
        case 200:
            baud = B200;
            break;
        case 300:
            baud = B300;
            break;
        case 600:
            baud = B600;
            break;
        case 1200:
            baud = B1200;
            break;
        case 1800:
            baud = B1800;
            break;
        case 2400:
            baud = B2400;
            break;
        case 4800:
            baud = B4800;
            break;
        case 9600:
            baud = B9600;
            break;
        case 19200:
            baud = B19200;
            break;
        case 57600:
            baud = B57600;
            break;
        case 38400:
            baud = B38400;
            break;
        case 115200:
            baud = B115200;
            break;
        case 230400:
            baud = B230400;
            break;
        case 460800:
            baud = B460800;
            break;
        case 500000:
            baud = B500000;
            break;
        case 576000:
            baud = B576000;
            break;
        case 921600:
            baud = B921600;
            break;
        case 1000000:
            baud = B1000000;
            break;
        case 1152000:
            baud = B1152000;
            break;
        case 1500000:
            baud = B1500000;
            break;
        case 2000000:
            baud = B2000000;
            break;
        case 2500000:
            baud = B2500000;
            break;
        case 3000000:
            baud = B3000000;
            break;
        case 3500000:
            baud = B3500000;
            break;
        case 4000000:
            baud = B4000000;
            break;
        default:
            custom_baud = true;
    }

    if (!custom_baud)
    {
        cfsetispeed(&options, baud);
        cfsetospeed(&options, baud);
    }

    // 数据位设置
    options.c_cflag &= (tcflag_t)~CSIZE;
    if (bytesize == kFiveBits)
        options.c_cflag |= CS5;
    else if (bytesize == kSixBits)
        options.c_cflag |= CS6;
    else if (bytesize == kSevenBits)
        options.c_cflag |= CS7;
    else if (bytesize == kEightBits)
        options.c_cflag |= CS8;
    else
    {
        std::cout << "Unsupported data bits.";
        return false;
    }

    // 停止位设置
    if (stopbits == kStopBitsOne)
        options.c_cflag &= (tcflag_t) ~(CSTOPB);
    else if (stopbits == kStopBitsTwo)
        options.c_cflag |= (CSTOPB);
    else
    {
        std::cout << "invalid stop bit";
        return false;
    }

    // 校验位设置
    options.c_iflag &= (tcflag_t) ~(INPCK | ISTRIP);
    if (parity == KParityNone)
    {
        options.c_cflag &= (tcflag_t) ~(PARENB | PARODD);
    }
    else if (parity == kParityEven)
    {
        options.c_cflag &= (tcflag_t) ~(PARODD);
        options.c_cflag |= (PARENB);
    }
    else if (parity == kParityOdd)
    {
        options.c_cflag |= (PARENB | PARODD);
    }
    else if (parity == kParityMark)
    {
        options.c_cflag |= (PARENB | CMSPAR | PARODD);
    }
    else if (parity == kParityMark)
    {
        options.c_cflag |= (PARENB | CMSPAR);
        options.c_cflag &= (tcflag_t) ~(PARODD);
    }
    else
    {
        std::cout << "invalid parity";
        return false;
    }

    // setup flow control
    if (flowcontrol == kFlowControlNone)
    {
        options.c_iflag &= (tcflag_t) ~(IXON | IXOFF | IXANY);
        options.c_cflag &= (unsigned long)~(CRTSCTS);
    }
    else if (flowcontrol == kFlowControlSoftware)
    {
        options.c_iflag |= (IXON | IXOFF);  //|IXANY)
        options.c_cflag &= (unsigned long)~(CRTSCTS);
    }
    else if (flowcontrol == kFlowcontrolHardware)
    {
        options.c_iflag &= (tcflag_t) ~(IXON | IXOFF | IXANY);
        options.c_cflag |= (CRTSCTS);
    }
    else
    {
        std::cout << "invalid flowcontrol";
        return false;
    }

    options.c_cc[VMIN] = 0;
    options.c_cc[VTIME] = 0;

    // activate settings
    if (tcsetattr(fd_, TCSANOW, &options) == -1)
    {
        std::cout << "tcsetattr failed";
        return false;
    }

    // apply custom baud rate, if any
    if (custom_baud)
    {
        struct serial_struct ser;
        if (-1 == ioctl(fd_, TIOCGSERIAL, &ser))
        {
            std::cout << "ioctl error";
            return false;
        }

        // set custom divisor
        ser.custom_divisor = ser.baud_base / static_cast<int>(baudrate);
        // update flags
        ser.flags &= ~ASYNC_SPD_MASK;
        ser.flags |= ASYNC_SPD_CUST;

        if (-1 == ioctl(fd_, TIOCSSERIAL, &ser))
        {
            std::cout << "ioctl error, set custom baudrate error";
            return false;
        }
    }

    return true;
}

bool SerialPort::WaitReadable(uint32_t timeout)
{
    // Setup a select call to block for serial data or a timeout
    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(fd_, &readfds);
    timespec timeout_ts(timespec_from_ms(timeout));
    int ret = pselect(fd_ + 1, &readfds, NULL, NULL, &timeout_ts, NULL);

    if (ret < 0)
    {
        // Select was interrupted
        if (errno == EINTR)
        {
            return false;
        }
        // Otherwise there was some error
        std::cout << "pselect, errno:" << errno << ", err:" << strerror(errno);
        return false;
    }
    // Timeout occurred
    if (ret == 0)
    {
        return false;
    }
    // This shouldn't happen, if r > 0 our fd has to be in the list!
    if (!FD_ISSET(fd_, &readfds))
    {
        std::cout
            << "select reports ready to read, but our fd isn't in the list, this shouldn't happen!";
        return false;
    }

    // Data available to read.
    return true;
}

int SerialPort::Write(char* buf, int count) { return write(fd_, buf, count); }