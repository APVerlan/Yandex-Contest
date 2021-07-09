#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

pair<long long, long long> FindMax(vector<long long>& arr, char c) {
	long long k = c == '-' ? -1 : 1,
		max1 = max(k * arr[0], k * arr[1]),
		max2 = min(k * arr[1], k * arr[0]);

	for (long long i = 2; i < arr.size(); i++) {
		if (k * arr[i] > max1) {
			max2 = max1;
			max1 = k * arr[i];
		}
		else if (k * arr[i] > max2) {
			max2 = k * arr[i];
		}
	}

	if (k == 1)
		return make_pair(max2 * k, max1 * k);
	else
		return make_pair(max1 * k, max2 * k);
}

int main() {
	long long a, old, i = 0;
	vector<long long> arr;
	
	while (cin >> a) {
		arr.push_back(a);
	}

	pair<long long, long long> p1 = FindMax(arr, '+'),
		p2 = FindMax(arr, '-'),
		pmax = (p1.first * p1.second > p2.first * p2.second) ? p1 : p2;

	cout << pmax.first << ' ' << pmax.second;

	return 0;
}