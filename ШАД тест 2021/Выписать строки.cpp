#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	cin.get();

	map<int, set<string>, less<int>> data;

	for (int i = 0; i < n; i++) {
		string line;
		getline(cin, line);

		data[line.length()].insert(line);
	}

	for (auto [key, value] : data) {
		for (auto it = value.begin(); it != value.end(); ++it) {
			cout << *it << '\n';
		}
	}

	return 0;
}