#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

bool IsPallindrom(vector<int>& v, int left, int right) {
	for (int i = 0; i < (right - left) / 2; i++) {
		if (v[left + i] != v[right - 1 - i])
			return false;
	}

	return true;
}

int main() {
	int n;
	cin >> n;

	vector<int> arr(n), add; 

	for (int k, i = 0; i < n; i++) {
		cin >> k;
		arr[i] = k;
	}

	int id = -1;
	for (int i = 0; i < n; i++) {
		if (IsPallindrom(arr, i, n)) {
			id = i;
			break;
		}
	}

	for (int i = id - 1; i >= 0; i--) {
		add.push_back(arr[i]);
	}

	cout << add.size() << endl;
	for (int it : add) {
		cout << it << ' ';
	}

	return 0;
}