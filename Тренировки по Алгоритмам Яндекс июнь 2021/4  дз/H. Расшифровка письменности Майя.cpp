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
	int n, m, counter = 0;
	char c;
	vector<char> v;
	unordered_map<char, int> word, direct;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> c;
		word[c]++;
	}

	for (int i = 0; i < m; i++) {
		cin >> c;;
		v.push_back(c);

		if (i > n - 1) {
			direct[c]++;
			direct[v[i - n]]--;

			if (!direct[v[i - n]])
				direct.erase(v[i - n]);

			if (direct == word)
				counter++;
		}
		else if (i == n - 1) {
			direct[c]++;

			if (direct == word)
				counter++;
		}
		else {
			direct[c]++;
		}
	}

	cout << counter;

	return 0;
}