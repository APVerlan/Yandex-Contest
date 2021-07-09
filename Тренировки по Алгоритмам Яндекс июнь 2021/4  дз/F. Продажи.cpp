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
	int count;
	string name, product;
	map<string, map<string, long long>> db;

	while (cin >> name >> product >> count) {
		db[name][product] += count;
	}

	for (auto& [key, m] : db) {
		cout << key << ":\n";
		for (auto& [pr, cnt] : m) {
			cout << pr << ' ' << cnt << endl;
		}
	}

	return 0;
}