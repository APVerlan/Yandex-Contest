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

	int x, y, prev_x, prev_y;
	cin >> prev_x >> prev_y;

	vector<int> vtx_l(n), vtx_r(n);
	vector<pair<int, int>> up(n);

	up[0] = make_pair(prev_x, prev_y);

	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		up[i] = make_pair(x, y);

		vtx_l[i] = vtx_l[i - 1] + (prev_y < y ? y - prev_y : 0);

		prev_y = y;
		prev_x = x;
	}

	for (int i = n - 2; i >= 0; i--) {
		vtx_r[i] = vtx_r[i + 1] + (up[i+1].second < up[i].second ? 
									up[i].second - up[i + 1].second : 0);
	}

	cin >> m;
	int left, right;
	for (int i = 0; i < m; i++) {
		cin >> left >> right;
		if (right > left) {
			cout << vtx_l[right - 1] - vtx_l[left - 1] << endl;
		}
		else {
			cout << vtx_r[right - 1] - vtx_r[left - 1] << endl;
		}
	}

	return 0;
}