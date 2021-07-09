#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	long long x, y;
	cin >> x >> y;

	long long counter = 0;
	if (y % x) {
		cout << counter;
		return 0;
	}

	y /= x;
	for (long long i = 2; i * i <= y; ++i) {
		if (y % i == 0) {
			counter++;
			while (y % i == 0) {
				y /= i;
			}
		}
	}

	if (y != 1) {
		counter++;
	}

	cout << (1ll << counter) << endl;
	return 0;
}