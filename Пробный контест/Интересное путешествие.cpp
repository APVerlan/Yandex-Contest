#include <vector>
#include <iostream>
#include <set>
#include <string>
#include <queue>

using namespace std;

long long BFS(long long from, long long to, long long dist, vector<vector<long long>>& distances) {
	vector<long long> distance_from(distances.size(), -1);
	distance_from[from] = (long long)(0);

	queue<long long> neighbors;
	neighbors.push(from);
	bool flag = false;

	while (!neighbors.empty()) {
		long long curr = neighbors.front();
		neighbors.pop();

		for (long long i = 0; i < distances.size(); ++i) {
			if (distance_from[i] == -1 && distances[curr][i] <= dist) {
				neighbors.push(i);
				distance_from[i] = distance_from[curr] + 1;
			}
		}
	}
	
	return distance_from[to];
}

int main() {
	long long n, dist, from, to;
	cin >> n;

	vector<pair<long long, long long>> coord;

	for (long long i = 0; i < n; ++i) {
		long long x, y;
		cin >> x >> y;
		coord.push_back(make_pair(x, y));
	}

	cin >> dist >> from >> to;
	
	vector<vector<long long>> distances(n, vector<long long>(n));
	
	for (long long i = 0; i < n; ++i) {
		for (long long j = 0; j < n; ++j) {
			if (i == j)
				distances[i][j] = 0;
			else
				distances[i][j] = abs(coord[i].first - coord[j].first) +
				abs(coord[i].second - coord[j].second);
		}
	}



	cout << BFS(from - 1, to - 1, dist, distances) << endl;

	return 0;
}