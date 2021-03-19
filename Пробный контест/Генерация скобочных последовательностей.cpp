#include <vector>
#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

void gen(int n, string& cur_seq, int cur_balance = 0, int cur_index = 0) {
	if (cur_index == 2 * n) {
		for (auto& bracket : cur_seq) {
			cout << bracket;
		}
		cout << endl;
	}
	else {
		if (cur_balance == 2 * n - cur_index) {

			cur_seq[cur_index] = ')';
			cur_balance--;
			gen(n, cur_seq, cur_balance, cur_index + 1);
		}
		else {

			cur_seq[cur_index] = '(';
			cur_balance++;
			gen(n, cur_seq, cur_balance, cur_index + 1);

			if (cur_balance > 1) {
				cur_seq[cur_index] = ')';
				cur_balance -= 2;
				gen(n, cur_seq, cur_balance, cur_index + 1);
			}
		}
	}
}

int main() {
	set<string> seq;
	
	int32_t n;
	cin >> n;
	string first_seq, copy;

	for (int i = 0; i < n; i++) {
		first_seq.push_back('(');
	}
	for (int i = 0; i < n; i++) {
		first_seq.push_back(')');
	}

	if (n) {
		gen(n, first_seq);
	}

	return 0;
}
