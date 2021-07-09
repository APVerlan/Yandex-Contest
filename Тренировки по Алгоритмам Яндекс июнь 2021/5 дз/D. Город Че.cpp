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
	long long n, r, res = 0;
	cin >> n >> r;

	vector<long long> dists(n);
	for (int i = 0; i < n; i++) {
		cin >> dists[i];
	}

	int i = 0, j = 1;
	for (; j < n;) {
		while (j < n && dists[j] - dists[i] <= r) j++;
		res += n - j;
		i++;
	}

	cout << res;

	return 0;
}