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
	int n, x, y;
	unordered_set<int> s;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		s.insert(x);
	}

	cout << s.size();
	return 0;
}