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
	unordered_map<string, int> dict;
	unordered_set<string> s;

	string l;
	int n, k;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> l;
			dict[l]++;
		}
	}

	for (auto [key, val] : dict) {
		if (val == n) s.insert(key);
	}

	cout << s.size() << endl;
	for (auto key : s) {
		cout << key << endl;
	}

	cout << dict.size() << endl;
	for (auto [key, val] : dict) {
		cout << key << endl;
	}
	return 0;
}