#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> first(n), second(k);

    for(int i = 0; i< n; i++) {
        cin >> first[i];
    }

    for(int i = 0; i< k; i++) {
        cin >> second[i];
    }

    sort(first.begin(), first.end());

    for (int item: second) {
        auto it = lower_bound(first.begin(), first.end(), item);
        if (it != first.end() && *it == item) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}