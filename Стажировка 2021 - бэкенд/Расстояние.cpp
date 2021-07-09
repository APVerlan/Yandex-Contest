#include <vector>
#include <iostream>
#include <set>
#include <unordered_map>
#include <map>
#include <string>
#include <algorithm>

using namespace std;
int main() {
	int n, k;
	cin >> n >> k;

	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[i] = make_pair(a, i);
	}

	sort(arr.begin(), arr.end(), 
		[](pair<int, int> & lhs, pair<int, int> & rhs) {
			return lhs.first < rhs.first;
		}
	);

	unordered_map<int, int> answers;

	#pragma omp parallel for
	for (int i = 0; i < arr.size(); i++) {
		int ans = 0;

		int m = i - 1, n = i + 1;

		for (int kk = k; kk > 0; --kk) {
			if (m >= 0) {
				if (n < arr.size()) {
					ans += abs(arr[m].first - arr[i].first) < abs(arr[n].first - arr[i].first) ? 
						abs(arr[m--].first - arr[i].first) : 
						abs(arr[n++].first - arr[i].first);
				}
				else {
					ans += abs(arr[m--].first - arr[i].first);
				}
			}
			else {
				ans += abs(arr[n++].first - arr[i].first);
			}
		}
		answers[arr[i].second] = ans;
	}

	cout << answers[0];
	for (int i = 1; i < n; i++) {
		cout << ' ' << answers[i];
	}

	return 0;
}