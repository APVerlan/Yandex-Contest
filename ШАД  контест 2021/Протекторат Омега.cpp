#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

int max_el(vector<int>& v) {
	int m = -1;
	for (auto it : v) {
		if (m < it)
			m = it;
	}

	return m;
}

int dfs(vector<vector<int>>& adj, vector<bool>& visited, int x, int dist) {
	visited[x] = true;
	dist++;
	int max_dist = dist;

	for (size_t i = 0; i < adj[x].size(); ++i) {
		if (!visited[adj[x][i]]) {
			int new_dist = dfs(adj, visited, adj[x][i], dist);
			if (max_dist < new_dist)
				max_dist = new_dist;
		}
	}

	return max_dist;
}

int bfs(vector<vector<int>>& adj, vector<int> distances, int s) {
	distances[s] = 0;
	int m = 0;

	queue<int> Q;
	Q.push(s);

	while (!Q.empty()) {
		int u = Q.front();
		Q.pop();

		for (auto v : adj[u]) {
			if (distances[v] == -1) {
				Q.push(v);
				distances[v] = distances[u] + 1;
				if (distances[v] > m)
					m = distances[v];
			}
		}
	}

	return m;
}

int main() {
	long long n;
	cin >> n;

	vector<vector<int>> adj(n);
	for (int i = 0; i < n - 1; i++) {
		int v1, v2;
		cin >> v1 >> v2;

		adj[v1 - 1].push_back(v2 - 1);
		adj[v2 - 1].push_back(v1 - 1);
	}

	vector<int> distances(adj.size(), -1);
	vector<bool> visited(adj.size());
	for (int i = 0; i < adj.size(); i++) {
		cout << dfs(adj, visited, i, -1) << ' ';
		for (int j = 0; j < adj.size(); j++) {
			visited[j] = false;
		}
	}

	return 0;
}