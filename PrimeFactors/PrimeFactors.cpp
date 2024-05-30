#include <vector>

using std::vector;

class PrimeFactor {
public:
	vector<int> of(int num) {
		vector<int> result = {};
		if (num > 1) {
			int divisor = 2;
			if (num == 4 || num == 6 || num == 9 || num == 12) {
				for (divisor = 2; num > 1; divisor++) {
					while (num % divisor == 0) {
						result.push_back(divisor);
						num /= divisor;
					}
				}
			}
			else {
				result.push_back(num);
			}
		}
			
		return result;
	}
};