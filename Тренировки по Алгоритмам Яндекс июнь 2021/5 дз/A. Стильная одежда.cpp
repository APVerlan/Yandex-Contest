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
	int n, m;

	cin >> n;
	vector<int> color_1(n);
	for (int i = 0; i < n; i++) {
		cin >> color_1[i];
	}
	
	cin >> m;
	vector<int> color_2(m);
	for (int i = 0; i < m; i++) {

		cin >> color_2[i];
	}

	int a = color_1[0], b = color_2[0], d = abs(color_1[0] - color_2[0]);
	/*
	brutforrce O(n^2)

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (d == -1 || d > abs(color_1[i] - color_2[j])) {
				d = abs(color_1[i] - color_2[j]);
				a = color_1[i];
				b = color_2[j];
			}
		}
	}*/

	for (int i = 0, j = 0; i < n && j < m;) {
		int dir_dist = abs(color_1[i] - color_2[j]);
		if (d > dir_dist) {
			d = abs(color_1[i] - color_2[j]);
			a = color_1[i];
			b = color_2[j];
		}

		if (j != m - 1 && abs(color_1[i] - color_2[j + 1]) < dir_dist) j++;
		else i++;
	}

	cout << a << ' ' << b;
	return 0;
}

