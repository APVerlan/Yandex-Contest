#include <vector>
#include <iostream>
#include <set>
#include <unordered_map>
#include <map>
#include <string>

using namespace std;

int main() {
	string F, S;
	unordered_map<char, int> table_1;
	unordered_map<char, int> table_2;
	
	getline(cin, F);
	getline(cin, S);

	for (char c : F) {
		table_1[c]++;
	}

	for (char c : S) {
		table_2[c]++;
	}

	if (table_1 == table_2)
		cout << 1;
	else cout << 0;

	return 0;
}