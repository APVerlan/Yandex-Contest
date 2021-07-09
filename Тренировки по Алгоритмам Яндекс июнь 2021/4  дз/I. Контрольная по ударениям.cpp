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

string str_tolower(string s) {
	std::transform(s.begin(), s.end(), s.begin(),
		[](unsigned char c) { return tolower(c); }
	);
	return s;
}

int AccentIdx(const string& s) {
	int idx = -1;
	bool flag = true;

	for (int i = 0; i < s.size(); i++) {
		if (isupper(s[i]) && idx == -1)  idx = i;
		else if (isupper(s[i]) && idx != -1) {
			flag = false;
		}
	}

	if (flag) return idx;
	else return -1;
}

int main() {
	int n, counter = 0;
	string word;
	cin >> n;
	
	unordered_map<string, unordered_set<int>> dict;

	for (int i = 0; i < n; i++) {
		cin >> word;
		dict[str_tolower(word)].insert(AccentIdx(word));
	}

	while (cin >> word) {
		if (dict.count(str_tolower(word)) &&
			!dict[str_tolower(word)].count(AccentIdx(word)) || AccentIdx(word) == -1)
			counter++;
	}

	cout << counter;
	return 0;
}