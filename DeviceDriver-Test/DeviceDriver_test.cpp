#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "DeviceDriver.h"

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
		std::cout << "\t\DeviceDriverTestFixture - SetUp" << std::endl;
		pDeviceDriver = new DeviceDriver(&flashDeviceMock);
	}

	// ����
	virtual void TearDown() {
		std::cout << "\t\DeviceDriverTestFixture - TearDown" << std::endl;
		delete pDeviceDriver;
	}
};

TEST(DeviceDriverTest, Read) {
}