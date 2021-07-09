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
	string line1, line2;

	getline(cin, line1);
	getline(cin, line2);

	unordered_set<int> s;
	for (int i = 0; i < line2.size() - 1; i++) {
		s.insert(100 * static_cast<int>(line2[i]) + 
			static_cast<int>(line2[i + 1]));
	}

	int counter = 0;
	for (int i = 0; i < line1.size() - 1; i++) {
		if (s.count(100 * static_cast<int>(line1[i]) +
			static_cast<int>(line1[i + 1])))
			counter++;
	}

	cout << counter;
	return 0;
}