#include <vector>
#include <iostream>
#include <set>
#include <unordered_map>
#include <map>
#include <string>
#include <algorithm>

const long long p = 1e9 + 7;

using namespace std;
int main() {
	long long n;
	cin >> n;

	vector<long long> pows(n * (n - 1) / 2 + 1);
	pows[0] = 1;
	for (int i = 1; i <= n * (n - 1) / 2; i++) {
		pows[i] = (pows[i - 1] << 1LL) % p;
	}

	if (n == 1) { 
		cout << 1;
		return 0; 
	}

	if (n == 2) {
		cout << 0;
		return 0;
	}

	long long result = pows[(n - 1) * (n - 2) / 2];
	for (int i = 2; i <= n; ++i) {
		result = (-result + pows[(n - i) * (n - i - 1) / 2]) % p;
	}
	/*
	long long counter = 1LL;

	for (long long i = n; i > 3; --i) {
		counter = (((i - 2LL) % p ) * counter) % p;
		counter = (counter * pows[i - 3LL]) % p;
	}
	cout << ((counter * n) % p ) % p;*/
	cout << ((result > 0) ? result : -result);
	return 0;
}