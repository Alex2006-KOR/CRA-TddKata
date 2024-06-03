#pragma once
class Application {
public:
	Application(DeviceDriver* _pDeviceDriver);
	void ReadAndPrint(int startAddr, int endAddr);
	void WriteAll(int value);

private:
	DeviceDriver * pDeviceDriver;
};

