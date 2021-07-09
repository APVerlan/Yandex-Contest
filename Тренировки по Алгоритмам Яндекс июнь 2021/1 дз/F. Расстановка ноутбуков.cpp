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
	int h1, l1, h2, l2;
	cin >> h1 >> l1 >> h2 >> l2;

	int min, h, l;
	h = max(h1, h2);
	l = l1 + l2;
	min = h * l;

	if ((h1 + l2) * max(h2, l1) < min) {
		h = max(h2, l1);
		l = h1 + l2;
		min = h * l;
	} 

	if ((l1 + h2) * max(l2, h1) < min) {
		h = max(l2, h1);
		l = l1 + h2;
		min = h * l;
	}

	if ((h2 + h1) * max(l2, l1) < min) {
		h = max(l2, l1);
		l = h1 + h2;
		min = h * l;
	}

	cout << h << ' ' << l;

	return 0;
}