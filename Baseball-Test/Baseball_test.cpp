#include "pch.h"
#include "Baseball.cpp"

TEST(BaseballTest, ThrowExceptionWhenInputLengthIsUnmached) {
	Baseball game;
	EXPECT_THROW(game.guess(string("12")), length_error);
}
