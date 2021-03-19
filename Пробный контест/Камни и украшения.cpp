#include <vector>
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	string J, S;
	
	getline(cin, J);
	getline(cin, S);
	
	size_t result = 0;
	set<char> set_J{ J.begin(), J.end() };

	for (char c : S) {
		if (set_J.count(c))
			result++;
	}

	cout << result;

	return 0;
}