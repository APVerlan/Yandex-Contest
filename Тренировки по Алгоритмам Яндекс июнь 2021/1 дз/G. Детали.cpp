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
	int N, K, M;
	cin >> N >> K >> M;
	int count = 0;

	if (K % M == 0)
		cout << (N / K) * (K / M) << endl;
	else if (M > K) cout << 0;
	else {
		int k2 = K / M;
		int i = 0;
		while (N >= K) {
			i++;
			int k1 = N / K;
			N -= k1 * K;
			N += (K - M * k2) * k1;

			count += k2 * k1;
		}

		cout << count << endl;
		return 0;
	}
}