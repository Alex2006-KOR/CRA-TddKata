#include "pch.h"
#include "SimilarityChecker.cpp"

TEST(SimilarityCheckerTest, GetStringLengthMaxScore) {
	SimilarityChecker checker;
	int expected = 60;
	EXPECT_EQ(expected, checker.getSimilarityScore("ABC", "ABC"));
}