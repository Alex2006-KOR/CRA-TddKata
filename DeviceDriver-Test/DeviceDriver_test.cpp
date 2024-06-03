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
	FlashMemoryDeviceMock flashDeviceMock;

	DeviceDriverMock()
		: DeviceDriver(&flashDeviceMock) {}

	MOCK_METHOD(int, read, (long address), (override));
	MOCK_METHOD(void, write, (long address, int data), ());
};

class DeviceDriverTestFixture : public testing::Test {
public:
	FlashMemoryDeviceMock flashDeviceMock;
	DeviceDriver *pDeviceDriver = nullptr;

	DeviceDriverMock deviceDriverMock;
	Application* pApplication = nullptr;

protected:
	// 초기화
	virtual void SetUp() {
		std::cout << "\tDeviceDriverTestFixture - SetUp" << std::endl;
		pDeviceDriver = new DeviceDriver(&flashDeviceMock);
		pApplication = new Application(&deviceDriverMock);
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
	int endAddr = 0xF;

	EXPECT_CALL(deviceDriverMock, read)
		.Times(((endAddr - startAddr) / 4 + 1))
		.WillRepeatedly(Return(0x04));
	pApplication->ReadAndPrint(startAddr, endAddr);
}

TEST_F(DeviceDriverTestFixture, ApplicationWriteAll) {
	EXPECT_CALL(deviceDriverMock, write)
		.Times(2);
	pApplication->WriteAll(0x00);
}