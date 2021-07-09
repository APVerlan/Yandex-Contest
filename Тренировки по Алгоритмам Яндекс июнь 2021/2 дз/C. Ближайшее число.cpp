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
	int n, b, idx, delta = -1;
	cin >> n;

	vector<int> arr(n);

	for (int k, i = 0; i < n; i++) {
		cin >> k;
		arr[i] = k;
	}
	cin >> b;
	
	for (int i = 0; i < n; i++) {
		if (abs(arr[i] - b) < delta || delta == -1) {
			delta = abs(arr[i] - b);
			idx = i;
		}
	}

	cout << arr[idx];

	return 0;
}