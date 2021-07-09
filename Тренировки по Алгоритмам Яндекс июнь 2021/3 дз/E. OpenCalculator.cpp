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
	int a;
	unordered_set<int> s1, s2;

	for (int i = 0; i < 3; i++) {
		cin >> a;
		s1.insert(a);
	}

	cin >> a;

	while (a / 10) {
		if (!s1.count(a % 10)) {
			s2.insert(a % 10);
		}
		a /= 10;
	}

	if (!s1.count(a % 10)) {
		s2.insert(a % 10);
	}

	cout << s2.size();

	return 0;
}