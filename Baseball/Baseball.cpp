#include <stdexcept>

using namespace std;

struct GuessResult {
	bool solved;
	int strikes;
	int balls;
};

class Baseball {
public:
	explicit Baseball(const string& question) 
		: question(question) {}

	GuessResult guess(const string& guessNumber) {
		assertIllegalArgument(guessNumber);

		if(guessNumber == question)
			return { true, 3, 0 };

		int strikes = 0, ball = 0;

		for (int cIdx = 0; cIdx < guessNumber.length(); cIdx++) {
			if (guessNumber[cIdx] == question[cIdx])
				strikes++;
		}

		return { false, strikes, 0 };
	}

private:
	string question;

	void assertIllegalArgument(const string& guessNumber) {
		if (guessNumber.length() != 3)
			throw length_error("Must be three letters.");

		for (char ch : guessNumber) {
			if (ch >= '0' || ch <= '9') continue;
			throw invalid_argument("Must be number");
		}

		if (isDuplicatedNumber(guessNumber))
			throw invalid_argument("Must be different number");
	}

	bool isDuplicatedNumber(const string& guessNumber) {
		if (guessNumber[0] == guessNumber[1] ||
			guessNumber[1] == guessNumber[2] ||
			guessNumber[2] == guessNumber[0])
			return true;
		return false;
	}
};