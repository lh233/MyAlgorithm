#pragma once

#include <atomic>
#include <functional>
#include <string>
#include <thread>

enum ByteSize
{
    kFiveBits = 5,
    kSixBits = 6,
    kSevenBits = 7,
    kEightBits = 8
};

enum Parity
{
    KParityNone = 0,
    kParityOdd = 1,
    kParityEven = 2,
    kParityMark = 3,
    kParitySpace = 4
};

enum StopBits
{
    kStopBitsOne = 1,
    kStopBitsTwo = 2
};

enum FlowControl
{
    kFlowControlNone = 0,
    kFlowControlSoftware = 1,
    kFlowcontrolHardware = 2
};

class SerialPort
{
   public:
    SerialPort();
    ~SerialPort();

    bool Start(const std::string& device, unsigned long baudrate);
    void Stop();
    void SetReadCallback(const std::function<void(const char*, std::size_t)>& callback) { read_callback_ = callback; }

    bool Open(const std::string& device);
    void Close();
    bool Setup(unsigned long baudrate, ByteSize bytesize = kEightBits, StopBits stopbits = kStopBitsOne,
               Parity parity = KParityNone, FlowControl flowcontrol = kFlowControlNone);
    bool WaitReadable(uint32_t timeout);
    int Write(char* buf, int count);

   protected:
    void Run();

   private:
    int fd_ = -1;  // File descriptor for the port
    std::atomic<bool> is_running_;
    std::thread thread_;
    std::function<void(const char*, std::size_t)> read_callback_;
};