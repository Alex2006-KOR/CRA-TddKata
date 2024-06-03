#include "DeviceDriver.h"
#include "Application.h"
#include <iostream>

Application::Application(DeviceDriver* _pDeviceDriver)
	: pDeviceDriver(_pDeviceDriver) {}

void Application::ReadAndPrint(int startAddr, int endAddr) {
	for (int addr = startAddr; addr <= endAddr; addr += 0x4) {
		std::cout << "Addr:" << addr << std::endl;
		std::cout << "Value: " << pDeviceDriver->read(addr) << std::endl;
	}
}

void Application::WriteAll(int value) {
	for (int addr = 0x00; addr <= 0x04; addr += 0x4)
		pDeviceDriver->write(addr, value);
}