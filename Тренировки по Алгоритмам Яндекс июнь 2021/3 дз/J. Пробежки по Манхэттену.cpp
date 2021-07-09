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
	int a, b, n, m;
	cin >> a >> b >> n >> m;

	int minimum = max(n + (n - 1) * a, m + (m - 1) * b), maximum = min(n + (n + 1) * a, m + (m + 1) * b);

	if (maximum < minimum) {
		cout << -1;
	}
	else {
		cout << minimum << ' ' << maximum;
	}

	return 0;
}