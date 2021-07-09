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
	int n, w, h;
	cin >> n;

	unordered_map<int, int> blocks;
	for (int i = 0; i < n; i++) {
		cin >> w >> h;
		if (!blocks.count(w)) blocks[w] = h;
		else if (blocks[w] < h) blocks[w] = h;
	}

	int height = 0;
	for (auto [key, val] : blocks) {
		height += val;
	}

	cout << height;

	return 0;
}