#include "json.hpp"

#include <iostream>
#include <string>
#include <vector>

using json = nlohmann::json;
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	vector<json> packets;
	for (int i = 0; i < n; ++i) {
		json j;
		cin >> j;
		packets.push_back(j);
	}

	int i = 0;
	json answer;

	for (auto& offers : packets) {
		for (auto& offer : offers["offers"]) {
			if (i < m) {
				answer["offers"].push_back(offer);
				++i;
			}
			else break;
		}

		if (i >= m) break;
	}

	cout << answer;
	return 0;
}