#include <vector>

using std::vector;

class PrimeFactor {
public:
	vector<int> of(int num) {
		vector<int> result = {};
		if (num > 1) {
			int divisor = 2;
			if (num == 4) {
				while (num % divisor == 0) {
					result.push_back(divisor);
					num /= divisor;
				}
			}
			else if (num == 6) {
				while (num % divisor == 0) {
					result.push_back(divisor);
					num /= divisor;
				}
				divisor++;
				while (num % divisor == 0) {
					result.push_back(divisor);
					num /= divisor;
				}
				divisor++;
			}
			else {
				result.push_back(num);
			}
		}
			
		return result;
	}
};