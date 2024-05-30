#include <stdexcept>

using namespace std;

class Baseball {
public:
	void guess(const string& string) {
		throw length_error("Must be three letters.");
	}
};