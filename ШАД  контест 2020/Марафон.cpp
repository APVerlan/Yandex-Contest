#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX_PAGE = 42200;
vector<long long> ranks(MAX_PAGE);

void ChangeRanks(long long old_page, long long new_page, bool flag) {
	if (flag) {
		for (int i = old_page + 1; i < MAX_PAGE - 1; i++) {
			ranks[i]--;
		}
	}

	for (int i = new_page + 1; i < MAX_PAGE - 1; i++) {
		ranks[i]++;
	}
}

int main() {
	unordered_map<long long, long long> users;
	long long n, new_page, user;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;

		if (command == "RUN") {
			cin >> user >> new_page;

			ChangeRanks(users[user], new_page, users.count(user));
			users[user] = new_page;
		}
		else if (command == "CHEER") {
			cin >> user;

			if (!users.count(user))
				cout << 0 << endl;
			else if (users.size() == 1)
				cout << 1 << endl;
			else 
				cout << (ranks[users[user]]) / ((users.size() - 1) * 1.0) << endl;
			
		}
	}
	return 0;
}