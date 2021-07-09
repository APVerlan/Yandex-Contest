#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

long long count_time(long long x, long long y, long long n_x, long long n_y) {
	return max(n_x * x, n_y * y);
}

int main() {
	long long	x, y, n;
	cin >> n >> x >> y ;

	long long left = 0, right = --n;
	while (right - left > 1) {
		long long mid = (right + left) / 2;

		if (count_time(x, y, n - mid, mid) > count_time(x, y, n - mid - 1, mid + 1)) left = mid;
		else right = mid;
	}
	cout << min(max(left * y, (n - left) * x), 
		max(right * y, (n - right) * x)) + min(x, y);

	return 0;
}