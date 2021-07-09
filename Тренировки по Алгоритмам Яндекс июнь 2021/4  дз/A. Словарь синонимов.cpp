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
	int n; 
	string word1, word2;
	unordered_map<string, string> dict;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> word1 >> word2;
		dict[word1] = word2;
		dict[word2] = word1;
	}

	cin >> word1;
	cout << dict[word1];

	return 0;
}