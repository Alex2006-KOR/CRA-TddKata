#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "DeviceDriver.cpp"
#include "Application.cpp"

using namespace testing;
using namespace std;

class FlashMemoryDeviceMock : public FlashMemoryDevice {
public:
	MOCK_METHOD(unsigned char, read, (long address), (override));
	MOCK_METHOD(void, write, (long address, unsigned char data), (override));
};


class DeviceDriverMock : public DeviceDriver {
public:
	DeviceDriverMock::DeviceDriverMock(FlashMemoryDevice* hardware)
		: DeviceDriver(hardware) {}

	MOCK_METHOD(int, read, (long address), ());
	MOCK_METHOD(void, write, (long address, int data), ());
};

class DeviceDriverTestFixture : public testing::Test {
public:
	FlashMemoryDeviceMock flashDeviceMock;
	DeviceDriver *pDeviceDriver;
	Application* pApplication;

protected:
	// 초기화
	virtual void SetUp() {
		std::cout << "\tDeviceDriverTestFixture - SetUp" << std::endl;
		pDeviceDriver = new DeviceDriver(&flashDeviceMock);
		pApplication = new Application(pDeviceDriver);
	}

	// 정리
	virtual void TearDown() {
		std::cout << "\tDeviceDriverTestFixture - TearDown" << std::endl;
		delete pDeviceDriver;
		delete pApplication;
	}
};

TEST_F(DeviceDriverTestFixture, Read5TimesRepetition) {
	EXPECT_CALL(flashDeviceMock, read)
		.Times(5)
		.WillRepeatedly(Return(0x12));
	pDeviceDriver->read(0x00);
}

TEST_F(DeviceDriverTestFixture, Read5TimesRepetitionException) {
	EXPECT_CALL(flashDeviceMock, read)
		.WillOnce(Return(0x12))
		.WillRepeatedly(Return(0x34));

	try {
		int ret = pDeviceDriver->read(0x00);
		FAIL();
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}

TEST_F(DeviceDriverTestFixture, Write) {
	EXPECT_CALL(flashDeviceMock, read)
		.Times(1)
		.WillRepeatedly(Return(0xFF));
	pDeviceDriver->write(0x00, 0x00);
}

TEST_F(DeviceDriverTestFixture, WriteException) {
	EXPECT_CALL(flashDeviceMock, read)
		.Times(1)
		.WillRepeatedly(Return(0x00));

	try {
		pDeviceDriver->write(0x00, 0x00);
		FAIL();
	}
	catch (exception& e) {
		cout << e.what() << endl;
	}
}

TEST_F(DeviceDriverTestFixture, ApplicationReadAndPrint) {
	int startAddr = 0x00;
	int endAddr = 0xFF;

	EXPECT_CALL(flashDeviceMock, read)
		.Times(((endAddr - startAddr)/4 + 1)*5)
		.WillRepeatedly(Return(0x00));

	pApplication->ReadAndPrint(startAddr, endAddr);
}