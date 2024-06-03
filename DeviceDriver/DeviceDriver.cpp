#include "DeviceDriver.h"

const int READ_REPEATITION_MAX_NUM = 5;

DeviceDriver::DeviceDriver(FlashMemoryDevice* hardware)
    : m_hardware(hardware) {}

int DeviceDriver::read(long address) {
    int ret = (int)(m_hardware->read(address));
    for (unsigned int readIdx = 0; readIdx < READ_REPEATITION_MAX_NUM - 1; readIdx++) {
        if ((int)(m_hardware->read(address)) != ret) {

        }
    }
    return ret;
}

void DeviceDriver::write(long address, int data) {
    // TODO: implement this method
    m_hardware->write(address, (unsigned char)data);
}