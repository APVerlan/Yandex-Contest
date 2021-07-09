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
	int a;
	string line1, line2;
	set<int> s1, s2, s12;
	
	getline(cin, line1);
	getline(cin, line2);

	istringstream ss1(line1), ss2(line2);

	while (ss1 >> a) {
		s1.insert(a);
	}

	while (ss2 >> a) {
		s2.insert(a);

		if (s1.count(a))
			s12.insert(a);
	}

	for (int it : s12) 
		cout << it << ' ';

	return 0;
}