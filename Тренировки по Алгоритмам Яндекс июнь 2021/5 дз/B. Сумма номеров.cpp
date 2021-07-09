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
	long long n, k;
	cin >> n >> k;

	vector<long long> arr(n);
	for (long long i = 0; i < n; i++) {
		cin >> arr[i];
	}

	long long sum = arr[0], counter = 0;
	for (long long i = 0, j = 0; j < n;) {
		if (sum == k) { 
			counter++;
			sum -= arr[i];

			if (i == j) {
				j++;
				sum += arr[j];
			}
			i++;
		}
		else if (sum > k) {
			sum -= arr[i];

			if (i == j) {
				j++;
				sum += arr[j];
			}
			i++;
		}
		else if (sum < k) {
			j++;
			if (j < n) sum += arr[j];
		}
	}

	cout << counter;

	return 0;
}