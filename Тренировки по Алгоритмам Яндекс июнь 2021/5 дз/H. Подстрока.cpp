#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int k;
	string line;
	unordered_map<char, int> dict;

	cin >> k >> k;
	cin >> line;

	int left = 0, right = 0, opt_l = 0, opt_r = 0;
	for (; right < line.size();) {
		while (right < line.size()) {
			if (dict[line[right]] < k) {
				dict[line[right++]]++;
			}
			else break;
		}

		if (right - left > opt_r - opt_l) {
			opt_l = left;
			opt_r = right;
		}

		dict[line[left++]]--;
	}

	cout << opt_r - opt_l<< ' ' << opt_l + 1;
	return 0;
}