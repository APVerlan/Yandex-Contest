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
	int a, counter = 0;
	vector<int> arr;
	while (cin >> a) {
		arr.push_back(a);
	}

	/*if (arr[0] > arr[1]) counter++;
	if (arr[arr.size() - 1] > arr[arr.size() - 2]) counter++;*/

	for (int i = 1; i < arr.size() - 1; i++) {
		if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) counter++;
	}

	cout << counter;

	return 0;
}