#include "pch.h"
#include "PrimeFactors.cpp"

using namespace std;

class PrimeFactorsTestFixure : public testing::Test {
public:
	PrimeFactor primeFactor;
	vector<int> expected;
};

TEST_F(PrimeFactorsTestFixure, Of1) {
	vector<int> expected = {};
	EXPECT_EQ(expected, primeFactor.of(1));
}

TEST_F(PrimeFactorsTestFixure, Of2) {
	vector<int> expected = {2};
	EXPECT_EQ(expected, primeFactor.of(2));
}