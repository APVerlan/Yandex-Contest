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
	int a, old, i = 0;
	
	while (cin >> a) {
		if (i == 0)
			old = a;
		else if (old >= a) {
			cout << "NO";
			return 0;
		}

		old = a;
		i++;
	}

	cout << "YES";
	return 0;
}