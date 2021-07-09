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
	int n, id = -1, min = -1, max = -1;
	cin >> n;

	vector<int> arr(n);
	unordered_set<int> id_max, id_min;

	for (int k, i = 0; i < n; i++) {
		cin >> k;

		if (k == max)
			id_max.insert(i);
		else if (k > max) {
			max = k;
			id_max.clear();
			id_max.insert(i);
		}

		if (k == min) 
			id_min.insert(i);
		else if (k < min || min == -1) {
			min = k;
			id_min.clear();
			id_min.insert(i);
		}
		
		arr[i] = k;
	}

	max = -1;
	for (auto i : id_min) {
		bool f = false;
		for (auto i_m : id_max) {
			if (i_m < i - 1) f = true;
		}

		if (i != 0) {
			if ((arr[i - 1] % 10) == 5 && max < arr[i - 1] && f) {
				max = arr[i - 1];
				id = i - 1;
			}
		}
	}

	if (id == -1 || n == id_min.size())
		cout << 0;
	else {
		int counter = 0;
		for (int k, i = 0; i < n; i++) {
			if (arr[i] <= arr[id]) counter++;
		}

		cout << n - counter + 1;
	}

	return 0;
}