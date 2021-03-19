#include <vector>
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	vector<int> binary_data;
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int item;
		cin >> item;
		binary_data.push_back(item);
	}
	
	size_t max = 0, direct = 0;
	
	for (int i = 0; i < n; i++) {
		if (binary_data[i] == 1) {
			++direct;
			max = max < direct ? direct : max;
		} else if (binary_data[i] == 0) {
			direct = 0;
		}
	}

	cout << max;

	return 0;
}