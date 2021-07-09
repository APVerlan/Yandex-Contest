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
	string word;
	unordered_map<string, int> words;

	while (cin >> word) {
		words[word]++;
	}

	int max = -1;
	for (auto& [key, val] : words) {
		if (max < val) {
			word = key;
			max = val;
		}
		else if (max == val && word > key) {
			word = key;
		}
	}

	cout << word;

	return 0;
}