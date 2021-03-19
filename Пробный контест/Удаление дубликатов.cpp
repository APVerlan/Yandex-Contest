#include <vector>
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	set<int32_t> data;
	
	int32_t n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int32_t item;
		cin >> item;
		data.insert(item);
	}
	
	for (int32_t item : data) {
		cout << item << endl;
	}

	return 0;
}