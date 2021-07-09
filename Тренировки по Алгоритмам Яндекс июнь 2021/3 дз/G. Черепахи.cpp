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
	int a, b, n, counter = 0;
	unordered_set<int> s;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a >= 0 && b >= 0 && a + b == n - 1) s.insert(a * 10000 + b);
	}

	cout << s.size();

	return 0;
}