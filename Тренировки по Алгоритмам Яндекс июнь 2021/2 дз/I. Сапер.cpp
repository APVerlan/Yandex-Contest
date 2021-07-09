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
	int n, m, num;
	cin >> n >> m >> num;

	vector<vector<char>> field(n, vector<char>(m));
	vector<pair<int, int>> bomb;

	for (int k = 0; k < num; k++) {
		int i, j;
		cin >> i >> j;

		bomb.push_back(make_pair(--i, --j));
		field[i][j] = '*';
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (field[i][j] != '*') {
				int counter = 0;
				
				for (auto p : bomb) {
					if (abs(i - p.first) < 2 && abs(j - p.second) < 2)
						counter++;
				}

				field[i][j] = '0' + counter;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j)
				cout << ' ';
			cout << field[i][j];
		}
		cout << '\n';
	}

	return 0;
}