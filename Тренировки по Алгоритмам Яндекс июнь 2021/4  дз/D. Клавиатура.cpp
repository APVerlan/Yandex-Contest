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
	int n, k;
	cin >> n;

	vector<int> resource(n );

	for (int i = 0; i < n; i++) {
		cin >> k;
		resource[i] = k;
	}
	
	cin >> n;
	string c;
	for (int i = 0; i < n; i++) {
		cin >> c;
		resource[atoi(c.c_str()) - 1]--;
	}

	for (int i = 0; i < resource.size(); i++) {
		if (resource[i] < 0) {
			cout << "YES\n";
		}
		else cout << "NO\n";
	}
}