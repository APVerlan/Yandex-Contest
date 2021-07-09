#include <iostream>
#include <vector>
#include <limits>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*int main() {
	int n;
	cin >> n;

	vector<int> data, max_, mins;

	for (int i = 0; i < n; i++) {
		int a, result = numeric_limits<int>::min();
		cin >> a;

		data.push_back(a);
		if (!max_.size()) {
			max_.push_back(a);
		} else {
			max_.push_back(max(a, max_[i - 1]));
		}

		mins.push_back(numeric_limits<int>::max());
		for (int j = 0; j < mins.size() - 1; j++) {
			if (mins[j] > a) {
				mins[j] = a;
			}
		}

		if (data.size() < 3) {
			cout << 0 << ' ';
		}
		else {
			result = numeric_limits<int>::min();
			for (int k = 1; k < data.size() - 1; k++) {
				if (result < max_[k - 1] - mins[k])
					result = max_[k - 1] - mins[k];
			}

			cout << result << ' ';
		}
	}

	return 0;
}*/

int main() {
	int n;
	cin >> n;

	vector<int> data;
	int a, id = 1, result = 0, maximum, minimum,
		global_min = numeric_limits<int>::max();
	for (int i = 0; i < n; i++) {
		cin >> a;

		data.push_back(a);
		if (i > 1 && global_min > data[data.size() - 3])
			global_min = data[data.size() - 3];

		if (data.size() == 3) {
			maximum = data[2];
			minimum = data[0];
			result = max(0, maximum - minimum);
			cout << result << ' ';
		}
		else if (data.size() > 3) {
			maximum = max(data[data.size() - 1], maximum);
			if (data[data.size() - 1] - global_min > maximum - minimum) {
				minimum = global_min;
				maximum = data[data.size() - 1];
			}
			result = max(0, maximum - minimum);
			cout << result << ' ';
		}
		else cout << 0 << ' ';
	}

	return 0;
}