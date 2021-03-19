#include <vector>
#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

void SeqGenerator(string& base, size_t left, 
	size_t right, bool flag, set<string>& data);

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
		copy = first_seq;
		seq.insert(first_seq);

		/*SeqGenerator(first_seq, 0, first_seq.size(), false, seq);
		SeqGenerator(copy, 0, copy.size(), true, seq);

		for (auto& s : seq) {
			cout << s << endl;
		}*/
		gen(n, first_seq);

	}

	return 0;
}

void SeqGenerator(string& base, size_t left, 
	size_t right, bool flag, set<string>& data) {
	if (right == 2)
		return;
	
	if (left == right - 2)
		return;
	
	if (!flag) {
		size_t begin = (right - 1) / 2 + 1, end = right - 1;
		for (size_t i = begin; i < end; ++i) {
			swap(base[i], base[i - 1]);
			data.insert(base);
		}

		SeqGenerator(base, left, right - 2, flag, data);
	} else {
		size_t begin = left + (right - 1 - left) / 2, end = left;
		for (int i = begin; i > end; i--) {
			swap(base[i], base[i + 1]);
			data.insert(base);
		}

		SeqGenerator(base, left + 2, right, flag, data);
	}
}