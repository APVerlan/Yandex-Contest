#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	long long n, m, a;
	cin >> n >> m;

	set<long long> s1, s2, s12;
	
	for (long long i = 0; i < n; i++) {
		cin >> a;
		s1.insert(a);
	}

	for (long long i = 0; i < m; i++) {
		cin >> a;
		s2.insert(a);

		if (s1.count(a))
			s12.insert(a);
	}

	cout << s12.size() << endl;
	for (long long it : s12)
		cout << it << ' ';

	cout << endl << s1.size() - s12.size() << endl;
	for (long long it : s1)
		if (!s12.count(it))
			cout << it << ' ';

	cout << endl << s2.size() - s12.size() << endl;
	for (long long it : s2)
		if (!s12.count(it))
			cout << it << ' ';

	return 0;
}