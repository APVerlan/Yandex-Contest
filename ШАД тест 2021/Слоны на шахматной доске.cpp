#include <iostream>
#include <vector>
#include <limits>
#include <unordered_map>
#include <algorithm>

using namespace std;

#include <iostream>
using namespace std;

long long squares(int i) { //количество полей по диагонали i
	if ((i & 1) == 1) return i / 4 * 2 + 1;
	else return (i - 1) / 4 * 2 + 2;
}

long long bishop_placements(int n, int k, long long** dp) {
	if (k > 2 * n - 1) return 0;
	for (int i = 0; i < n * 2; i++) dp[i][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i < n * 2; i++) {
		for (int j = 1; j <= k; j++)
			dp[i][j] = dp[i - 2][j] + dp[i - 2][j - 1] * (squares(i) - j + 1);
	}
	long long res = 0;
	for (int i = 0; i <= k; i++) {
		res += dp[n * 2 - 1][i] * dp[n * 2 - 2][k - i];
	}
	return res;
}

int main() {
	int n;
	cin >> n;

	int k = 3;
	long long** dp = new long long* [n * 2]; //таблица для расчета
	for (int i = 0; i < n * 2; i++) {
		dp[i] = new long long[k + 1];
		for (int j = 0; j < k + 1; j++) dp[i][j] = 0LL;
	}

	long long  m = n * n, result = m * (m - 1) * (m - 2) / 6;
	bishop_placements(n, k, dp);
 
	long long bad_0 = (m / 2) * ((m / 2) - 1) * ((m / 2) - 2) / 6, bad_1 = (n % 2 ? (m / 2 + 1) : m / 2) * (m / 2) * ((m / 2) - 1) / 2,
		bad_2 = (n > 1) ? (m / 2) * dp[2 * n - 1][2] : 0, bad_3 = (n > 2) ? dp[2 * n - 1][3] : 0;

	cout << result - bad_0 - bad_1 - bad_2 - bad_3;
	return(0);
}