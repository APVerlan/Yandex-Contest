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
	cin >> k >> line;

	int c_right, c_left, left = 0, right = k - 1;
	long long count = 0;
	for (; right < line.size() - 1;) {
		c_right = right, c_left = left;
		int i = 1;
		while (true) {
			if (line[c_left++] == line[++c_right]) count += i++;
			else break;
		}
		
		left = c_left, right = c_right;
	}

	cout << count;
	return 0;
}