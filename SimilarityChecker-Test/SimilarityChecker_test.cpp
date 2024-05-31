#include "pch.h"
#include "SimilarityChecker.cpp"

#include <vector>

using std::vector;

struct TestVector_t {
	int expected;
	string srcStr;
	string dstStr;
};

class SimilarityCheckerTestFixture : public SimilarityChecker, public testing::Test {
public:
	void doLengthTest(vector<TestVector_t> tv) {
		for (auto& v : tv)
			EXPECT_EQ(v.expected, getLengthScore(v.srcStr, v.dstStr));
	}
};

TEST_F(SimilarityCheckerTestFixture, DoLengthScoreTest) {
	vector<TestVector_t> tv = {
		{60, "ABC", "DEF"},
		{30, "ABCDEF", "GHIK"},
		{0, "ABCDEF", "GHI"}
	};
	doLengthTest(tv);
}