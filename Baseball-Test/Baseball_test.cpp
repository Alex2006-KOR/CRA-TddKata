#include "pch.h"
#include "Baseball.cpp"

class BaseballTestFixture : public testing::Test {
public:
	Baseball game;
	void assertIllegalArgument(string guessNumber) {
		try {
			game.guess(string("12s"));
			FAIL();
		}
		catch (exception e) {
			// PASS
		}
	}
};

TEST_F(BaseballTestFixture, ThrowExceptionWhenInvalidCase) {
	assertIllegalArgument("12");
	assertIllegalArgument("12s");
}