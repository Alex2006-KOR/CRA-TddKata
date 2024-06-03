#include "DeviceDriver.h"
#include <stdexcept>

const int READ_REPEATITION_MAX_NUM = 5;

class ReadFailException : public std::exception {
    char const* what() const override {
        return "Read Different value from same Address";
    }
};

class WriteFailException : public std::exception {
    char const* what() const override {
        return "Write address is not empty";
    }
};

DeviceDriver::DeviceDriver(FlashMemoryDevice* hardware)
    : m_hardware(hardware) {}

int DeviceDriver::read(long address) {
    int ret = (int)(m_hardware->read(address));
    for (unsigned int rIdx = 0; rIdx < READ_REPEATITION_MAX_NUM - 1; rIdx++)
        if ((int)(m_hardware->read(address)) != ret)
            throw ReadFailException();
    return ret;
}

void DeviceDriver::write(long address, int data) {
    if ((int)(m_hardware->read(address)) == 0xFF)
        m_hardware->write(address, (unsigned char)data);
    else
        throw WriteFailException();
}