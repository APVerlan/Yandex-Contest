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
	int a, b, c;
	cin >> a >> b >> c;

	if (a + b > c && a + c > b && c + b > a) cout << "YES";
	else cout << "NO";

	return 0;
}