#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;
/*
bool IsPalindrom(string&& s) {
	if (s.size() == 1)
		return true;

	for (int i = 0; i < s.size() / 2 + 1; i++) {
		if (s[i] != s[s.size() - 1 - i])
			return false;
	}

	return true;
}

int main() {
	long long n;
	cin >> n;

	vector<string> words(n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		words[i] = move(s);
	}

	vector<pair<int, int>> ans;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (IsPalindrom(words[i] + words[j]))
				ans.push_back(make_pair(i + 1, j + 1));

			if (IsPalindrom(words[j] + words[i]))
				ans.push_back(make_pair(j + 1, i + 1));
		}
	}

	sort(ans.begin(), ans.end());
	for (auto p : ans) {
		cout << p.first << ' ' << p.second << endl;
	}

	return 0;
}*/

	struct TrieNode {
		unordered_map<char, TrieNode*> child;

		int index = -1;
	}*root;

	void Insert(string word, int idx) {
		TrieNode* temp = root;

		for (auto i : word) {
			if (!temp->child.count(i)) temp->child[i] = new TrieNode();
			temp = temp->child[i];
		}


		temp->index = idx;
	}

	int Search(string word) {
		TrieNode* temp = root;
		for (auto i : word) {
			if (!temp->child.count(i)) return -1;
			temp = temp->child[i];
		}
		return temp->index;
	}

	bool IsPalindrom(string& s) {
		int l = 0, r = s.size() - 1;
		while (l <= r) {
			if (s[l] == s[r]) l++, r--;
			else return false;
		}
		return true;
	}

int main() {
	long long n;
	cin >> n;

	vector<string> words(n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		words[i] = move(s);
	}

	root = new TrieNode();

	for (int i = 0; i < n; i++) {
		string s = words[i];
		reverse(s.begin(), s.end());
		Insert(s, i);
	}

	set<pair<int, int>> pals;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= words[i].size(); j++) {
			string left = words[i].substr(0, j), rem = words[i].substr(j);

			int idx = Search(left);
			if (idx != -1 && IsPalindrom(rem) && idx != i) {
				pals.insert({ i,idx });
			}

			idx = Search(rem);
			if (idx != -1 && IsPalindrom(left) && idx != i) {
				pals.insert({ idx,i });
			}
		}
	}


	vector<pair<int, int>> ans;
	for (auto i : pals) {
		ans.push_back(i);
	}

	for (auto i : ans)
		cout << i.first + 1 << " " << i.second + 1 << endl;

	return 0;
}