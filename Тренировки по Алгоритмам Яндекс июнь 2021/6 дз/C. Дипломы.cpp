#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    long long w, h, n;
    cin >> w >> h >> n;

    long long l = w, r = w*n, mid, res;
    while (r - l > 1) {
        mid = (l + r) / 2;
        res = (mid / w) * (mid / h);

        if (res < n) l = mid;
        else r = mid;
    }

    cout << r;
    return 0;
}