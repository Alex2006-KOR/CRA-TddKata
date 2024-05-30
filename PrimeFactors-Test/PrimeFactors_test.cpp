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

TEST_F(PrimeFactorsTestFixure, Of3) {
	vector<int> expected = { 3 };
	EXPECT_EQ(expected, primeFactor.of(3));
}

TEST_F(PrimeFactorsTestFixure, Of4) {
	vector<int> expected = { 2, 2 };
	EXPECT_EQ(expected, primeFactor.of(4));
}

TEST_F(PrimeFactorsTestFixure, Of6) {
	vector<int> expected = { 2, 3 };
	EXPECT_EQ(expected, primeFactor.of(6));
}

TEST_F(PrimeFactorsTestFixure, Of9) {
	vector<int> expected = { 3, 3 };
	EXPECT_EQ(expected, primeFactor.of(9));
}