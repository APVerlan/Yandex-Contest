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
	int n, k, left = 0, right = -1;
	cin >> n >> k;

	vector<int> arr(n);
	unordered_map<int, int> tr;
	for (int i = 0; i < n; i++){
		cin >> arr[i];

		if (right == -1) {
			tr[arr[i]]++;

			if (tr.size() == k)
				right = i;
		}
	}

	int m_left = left, m_right = right;
	for (; right < n;) {

		while (true) {
			if (tr[arr[left]] > 1) {
				tr[arr[left++]]--;
			}
			else break;
		}

		if (m_right - m_left > right - left) {
			m_right = right;
			m_left = left;
		}

		right++;
		if (right < n) tr[arr[right]]++;
	}
	
	cout << m_left + 1 << ' ' << m_right + 1;

	return 0;
}