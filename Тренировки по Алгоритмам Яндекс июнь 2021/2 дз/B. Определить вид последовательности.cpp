#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

enum class SEQ {
	CONSTANT, 
	ASCENDING, 
	WEAKLY_ASCENDING,
	DESCENDING, 
	WEAKLY_DESCENDING, 
	RANDOM
};

const vector<string> v = {"CONSTANT", "ASCENDING", "WEAKLY ASCENDING", 
						"DESCENDING", "WEAKLY DESCENDING", "RANDOM"};

const int END = -2000000000;

int main() {
	int a, old, i = 0;
	bool flag = true;
	SEQ s = SEQ::CONSTANT;
	
	while (cin >> a && a != END) {
		if (flag) {
			flag = false;
		}
		else {
			if (a > old) {
				if (s == SEQ::DESCENDING || s == SEQ::WEAKLY_DESCENDING) 
					s = SEQ::RANDOM;
				if (s == SEQ::CONSTANT) { 
					if (i != 1) s = SEQ::WEAKLY_ASCENDING; 
					else s = SEQ::ASCENDING; 
				}
			}
			
			if (a == old) {
				if (s == SEQ::DESCENDING) s = SEQ::WEAKLY_DESCENDING;
				if (s == SEQ::ASCENDING) s = SEQ::WEAKLY_ASCENDING;
			}
			
			if (a < old) {
				if (s == SEQ::ASCENDING || s == SEQ::WEAKLY_ASCENDING)
					s = SEQ::RANDOM;
				if (s == SEQ::CONSTANT) {
					if (i != 1) s = SEQ::WEAKLY_DESCENDING;
					else s = SEQ::DESCENDING;
				}
			}
		}

		old = a;
		i++;
	}

	cout << v[static_cast<int>(s)];
	return 0;
}