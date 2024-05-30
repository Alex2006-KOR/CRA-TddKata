#include "pch.h"
#include "Baseball.cpp"

TEST(BaseballTest, ThrowExceptionWhenInputLengthIsUnmached) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}

TEST(BaseballTest, ThrowExceptionWhenInputInvalidChar) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12s")), invalid_argument);
}
TEST(BaseballTest, ThrowExceptionWhenInputInvalidChar) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12s")), invalid_argument);
}