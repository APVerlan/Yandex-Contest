#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

struct PhoneNumber {
	int code = 495;
	int number;
};

bool operator==(PhoneNumber lhs, PhoneNumber rhs) {
	return (lhs.code == rhs.code && lhs.number == rhs.number);
}

PhoneNumber ParseNumber(string& line) {
	PhoneNumber p_num;
	string clear_line;

	for (char c : line) {
		if (c == '+' || isdigit(c)) {
			clear_line.push_back(c);
		}
	}

	size_t it = 0;
	if (clear_line[it] == '+') it = 2;
	else if (clear_line[it] == '8' && clear_line.size() > 7) it = 1;
	
	if (it == 0)
		p_num.number = stoi(clear_line);
	else {
		p_num.code = stoi(clear_line.substr(it, 3));
		p_num.number = stoi(clear_line.substr(it + 3));
	}

	return p_num;
}

int main() {
	PhoneNumber new_num, old_num;
	string line;

	cin >> line;
	new_num = ParseNumber(line);

	for (int i = 0; i < 3; i++) {
		cin >> line;
		old_num = ParseNumber(line);

		if (old_num == new_num)
			cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}