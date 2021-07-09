#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	long long n;
	cin >> n;

	vector<int> arr(n);
	unordered_map<int, int> idxs;
	unordered_map<int, set<int>> repeaters;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[i] = a;
		
		idxs[a] = i;
		repeaters[a].insert(i);
	}

	vector<int> del;
	for (auto [key, s] : repeaters) {
		if (s.size() == 1)
			del.push_back(key);
	}

	for (auto val : del) {
		repeaters.erase(val);
	}

	int m;
	cin >> m;

	int k = arr[m - 1];

	del.clear();
	for (int i = 0; i < n; i++) {
		if (!repeaters.count(arr[i]))
			del.push_back(arr[i]);
	}

	if (m - 1 < del.size())
		cout << idxs[del[m - 1]] + 1 << endl;
	else cout << 0 << endl;

	return 0;
}