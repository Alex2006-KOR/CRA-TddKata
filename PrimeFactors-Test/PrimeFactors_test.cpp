#include "pch.h"
#include "PrimeFactors.cpp"

using namespace std;

TEST(PrimeFactors, PrimeTest) {
	PrimeFactor primeFactor;
	vector<int> expected = {};
	EXPECT_EQ(expected, primeFactor.of(1));
}