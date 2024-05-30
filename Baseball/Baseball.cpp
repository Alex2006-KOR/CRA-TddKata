#include <stdexcept>

using namespace std;

class Baseball {
public:
	void guess(const string& guessNumber) {
		if(guessNumber.length() != 3)
			throw length_error("Must be three letters.");

		for (char ch : guessNumber)
			if (ch < '0' || ch > '9')
				throw invalid_argument("Must be number");
	}
};