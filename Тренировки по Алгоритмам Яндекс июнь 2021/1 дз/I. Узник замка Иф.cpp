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
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;

	vector<int> otv, kp;

	otv.push_back(d);
	otv.push_back(e);
	sort(otv.begin(), otv.end());

	kp.push_back(a);
	kp.push_back(b);
	kp.push_back(c);
	sort(kp.begin(), kp.end());
	kp.pop_back();

	if (kp <= otv)
		cout << "YES";
	else cout << "NO";

	return 0;
}