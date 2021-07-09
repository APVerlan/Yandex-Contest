#include <iostream>
#include <string>
#include <sstream>
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
	ostringstream stream;
	unordered_map<string, int> words;


	while (cin >> word) {
		if (!words.count(word))
			stream << 0 << ' ';
		else stream << words[word] << ' ';
		
		words[word]++;
	}

	cout << stream.str();

	return 0;
}