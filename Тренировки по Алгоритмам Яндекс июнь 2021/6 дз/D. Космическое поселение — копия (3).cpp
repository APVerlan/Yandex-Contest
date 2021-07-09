#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

#define inc(a, b) (a % b ? a / b + 1 : a / b)

using namespace std;


bool correct(long long a, long long b, long long w,
	long long h, long long n, long long d ) {
	long long side_a = a + 2*d, side_b = b + 2*d;
	
	bool f = false, s = false;
	if (w / side_a != 0 && inc(n, (w / side_a)) * side_b <= h)  f = true;
	if (w / side_b != 0 && inc(n, (w / side_b)) * side_a <= h)  s = true;

	return (f || s);
}

int main() {
	long long w, h, n, a, b;
	cin >> n >> a >> b >> w >> h;

	long long l = 0, r = w * n, mid;
	while (r - l > 0) {
		mid = (l + r) / 2;

		if (correct(a, b, w, h, n, mid)) l = mid;
		else r = mid;
	}

	if (correct(a, b, w, h, n, r)) cout << r;
	else cout << l;
	return 0;
}