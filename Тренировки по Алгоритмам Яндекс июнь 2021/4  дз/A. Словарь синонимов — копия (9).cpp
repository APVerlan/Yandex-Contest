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
	unordered_set<int> s;

	while (cin >> a) {
		s.insert(a);
	}

	cout << s.size();

	return 0;
}