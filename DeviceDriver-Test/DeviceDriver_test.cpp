#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "DeviceDriver.cpp"

using namespace testing;
using namespace std;

class FlashMemoryDeviceMock : public FlashMemoryDevice {
public:
	MOCK_METHOD(unsigned char, read, (long address), (override));
	MOCK_METHOD(void, write, (long address, unsigned char data), (override));
};	

class DeviceDriverTestFixture : public testing::Test {
public:
	FlashMemoryDeviceMock flashDeviceMock;
	DeviceDriver* pDeviceDriver;

protected:
	// 초기화
	virtual void SetUp() {
		std::cout << "\tDeviceDriverTestFixture - SetUp" << std::endl;
		pDeviceDriver = new DeviceDriver(&flashDeviceMock);
		
	}

	// 정리
	virtual void TearDown() {
		std::cout << "\tDeviceDriverTestFixture - TearDown" << std::endl;
		delete pDeviceDriver;
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