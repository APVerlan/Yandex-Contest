#include <vector>
#include <iostream>
#include <set>
#include <unordered_map>
#include <map>
#include <string>

using namespace std;

bool IsIncr(vector<int>& arr, int& sum) {
	int prev = arr[0];

	for (int item : arr) {
		if (item < prev) {
			return false;
		}
		else if (item > prev) {
			sum += (item - prev);
		}

		prev = item;
	}

	return true;
}

int Sum(vector<int>& arr) {
	int sum = 0;
	for (int it : arr)
		sum += it;

	return sum;
}

int main() {
	int n, sum = 0;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[i] = a;
	}

	if (!IsIncr(arr, sum)) {
		cout << -1;
		return 0;
	}

	cout << sum;
	return 0;
}