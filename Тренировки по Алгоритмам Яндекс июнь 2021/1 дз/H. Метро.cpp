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
	
	int min_a = n + (n - 1) * a, max_a = n + (n + 1) * a,
		min_b = m + (m - 1) * b, max_b = m + (m + 1) * b;

	return 0;
}