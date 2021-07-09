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
	int n, m;
	cin >> n;

	vector<int> clas_power(n);
	for (int i = 0; i < n; i++) {
		cin >> clas_power[i];
	}
	
	cin >> m;

	map<int, int> power_by_price;
	for (int i = 0; i < m; i++) {
		int k, v;
		cin >> k >> v;

		if (power_by_price.count(k)) {
			if(power_by_price[k] > v) power_by_price[k] = v;
		} else power_by_price[k] = v;
	}

	int res = 0;
	for (auto p : clas_power) {
		auto it = power_by_price.lower_bound(p);
		
		int min = it->second;
		for (; it != power_by_price.end(); it++) {
			if(min > it->second)
				min = it->second;
		}
		res += min;
	}

	cout << res;

	return 0;
}