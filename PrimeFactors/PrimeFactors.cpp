#include <vector>

using std::vector;

class PrimeFactor {
public:
	vector<int> of(int i) {
		vector<int> result = {};
		if (i == 2) {
			result.push_back(2);
		}
		return result;
	}
};