#include "pch.h"
#include "PrimeFactors.cpp"

using namespace std;

TEST(PrimeFactors, Of1) {
	PrimeFactor primeFactor;
	vector<int> expected = {};
	EXPECT_EQ(expected, primeFactor.of(1));
}

TEST(PrimeFactors, Of2) {
	PrimeFactor primeFactor;
	vector<int> expected = {2};
	EXPECT_EQ(expected, primeFactor.of(2));
}