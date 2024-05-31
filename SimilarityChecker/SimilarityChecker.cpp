#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using std::string;
using std::vector;

class SimilarityChecker {
public:
	int getSimilarityScore(string str1, string str2) {
		return getLengthScore(str1, str2) + getAlphaSocre(str1, str2);
	}

protected:
	int getAlphaSocre(string str1, string str2) {
		if (str1.length() < str2.length())
			std::swap(str1, str2);

		int tCnt = getTotalAlpha(str1, str2);
		int sCnt = getSameAlpha(str1, str2);

		return sCnt * 40 / tCnt;
	}

	int getLengthScore(string str1, string str2) {
		if (str1.length() == str2.length())
			return 60;

		int lLen = str1.length();
		int sLen = str2.length();

		if (lLen < sLen)
			std::swap(lLen, sLen);

		return (sLen * 2 - lLen) * 60 / sLen;
	}

private:
	int getSameAlpha(string str1, string str2) {
		int ret = 0;

		vector<char> str1Vector = getUniqueAlpha(str1);
		vector<char> str2Vector = getUniqueAlpha(str2);

		for (auto c : str2Vector)
			if (find(str1Vector.begin(), str1Vector.end(), c) != str1Vector.end()) ret++;

		return ret;
	}

	int getTotalAlpha(string str1, string str2) {
		return getUniqueAlpha(str1 + str2).size();
	}

	vector<char> getUniqueAlpha(string str) {
		vector<char> charVector;

		for (auto c : str)
			charVector.push_back(c);

		sort(charVector.begin(), charVector.end());
		charVector.erase(unique(charVector.begin(), charVector.end()), charVector.end());
		
		return charVector;
	}
};