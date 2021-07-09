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

	if (c < 0 || (a == 0 && b != c * c))
		cout << "NO SOLUTION";
	else if(a == 0 && b == c*c) {
		cout << "MANY SOLUTIONS";
	}
	else {
		if((c * c - b) % a)
			cout << "NO SOLUTION";
		else
			cout << (c * c - b) / a;
	}

	return 0;
}