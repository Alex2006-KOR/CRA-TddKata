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
	// �ʱ�ȭ
	virtual void SetUp() {
		std::cout << "\tDeviceDriverTestFixture - SetUp" << std::endl;
		pDeviceDriver = new DeviceDriver(&flashDeviceMock);
		
	}

	// ����
	virtual void TearDown() {
		std::cout << "\tDeviceDriverTestFixture - TearDown" << std::endl;
		delete pDeviceDriver;
	}
};

TEST_F(DeviceDriverTestFixture, Read) {
	EXPECT_CALL(flashDeviceMock, read)
		.Times(5)
		.WillRepeatedly(Return(0x12));
	pDeviceDriver->read(0x00);
}