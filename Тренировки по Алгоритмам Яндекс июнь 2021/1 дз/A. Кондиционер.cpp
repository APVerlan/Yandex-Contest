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
	int room, cond;
	string command;

	cin >> room >> cond >> command;

	if (command == "freeze" && room > cond) {
		room = cond;
	}
	else if (command == "heat" && room < cond) {
		room = cond;
	}
	else if (command == "auto") {
		room = cond;
	}

	cout << room;
	return 0;
}