#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define inc(a, b) (a % b ? a / b + 1 : a / b)

using namespace std;

pair<long long, long long> amean(long long a, long long b,
	long long c, long long d) {
	long long sum = a + b + c + d;

	return make_pair((2 * a + 3 * b + 4 * c + 5 * d) / sum, (2 * a + 3 * b + 4 * c + 5 * d) % sum);
}

int main() {
	long long a, b, c;
	cin >> a >> b >> c;

	pair<long long, long long> res;
	long long l = 0, r = 2 * a + b + c, mid;
	while (r - l > 1) {
		mid = (l + r) / 2;

		res = amean(a, b, c, mid);
		if (res.first < 3 ||
			(res.first == 3 && res.second * 2 < (a + b + c + mid))) l = mid;
		else r = mid;
	}

	res = amean(a, b, c, l);
	if (res.first >= 4 || (res.first == 3 && res.second * 2 >= (a + b + c + l))) cout << l;
	else cout << r;
	return 0;
}