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
		max2 = min(k * arr[1], k * arr[0]),
		id1 = (k * arr[0] > k * arr[1] ? 0 : 1),
		id2 = (k * arr[0] > k * arr[1] ? 1 : 0);

	for (long long i = 2; i < arr.size(); i++) {
		if (k * arr[i] > max1) {
			max2 = max1;
			id2 = id1;
			max1 = k * arr[i];
			id1 = i;
		}
		else if (k * arr[i] > max2) {
			max2 = k * arr[i];
			id2 = i;
		}
	}

	if (k == 1)
		return make_pair(id2, id1);
	else
		return make_pair(id1, id2);
}

long long FindThird(vector<long long>& arr, int id1, int id2) {
	long long k = (arr[id1] * arr[id2] > 0) ? 1 : -1,
		max = -1, id3;

	for (long long i = 0; i < arr.size(); i++) {
		if (i != id1 && i != id2 && (k * arr[i] > max || max == -1)) {
			max = arr[i];
			id3 = i;
		}
	}

	return id3;
}

int main() {
	long long a;
	vector<long long> arr;

	while (cin >> a) {
		arr.push_back(a);
	}

	pair<long long, long long> p1 = FindMax(arr, '+'),
		p2 = FindMax(arr, '-');

	long long id3_1 = FindThird(arr, p1.first, p1.second),
		id3_2 = FindThird(arr, p2.first, p2.second);

	if (arr[p1.first] * arr[p1.second] * arr[id3_1] >
		arr[p2.first] * arr[p2.second] * arr[id3_2])
		cout << arr[p1.first] << ' ' << arr[p1.second] << ' ' << arr[id3_1];
	else
		cout << arr[p2.first] << ' ' << arr[p2.second] << ' ' << arr[id3_2];

	return 0;
}