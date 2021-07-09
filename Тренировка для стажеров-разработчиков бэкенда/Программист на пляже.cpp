#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

bool chek(int a, int b, int l, 
	int r, vector<unordered_set<int>>& servers) {
	for (int i = l; i <= r; ++i) {
		if (!servers[a - 1].count(i))
			return false;
	}
	return true;
}

void transfer(int a, int b, int l,
	int r, vector<unordered_set<int>>& servers) {
	for (int i = l; i <= r; ++i) {
		servers[a - 1].erase(i);
		servers[b - 1].insert(i);
	}
}

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	
	vector<unordered_set<int>> servers(m);

	for (int i = 0; i < n; ++i) {
		int chank;
		cin >> chank;

		servers[chank - 1].insert(i + 1);
	}

	for (int i = 0; i < q; ++i) {
		int a, b, l, r;
		cin >> a >> b >> l >> r;

		if (!chek(a, b, l, r, servers)) {
			cout << 0 << endl;
			continue;
		}
		else { 
			cout << 1 << endl; 
			transfer(a, b, l, r, servers);
		}
	}

	return 0;
}