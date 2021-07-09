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
	unordered_set<string> s;
	while (cin >> word) s.insert(word);

	cout << s.size();
}