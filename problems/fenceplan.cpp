#include <cmath>
#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int n, m;
vector<int> x;
vector<int> y;
vector<vector<int> > adj;
vector<bool> visited;

int dfs(int node, int maxX, int minX, int maxY, int minY) {
	if (visited[node]) return 0;
	visited[node] = true;
	// represents current perimeter / 2
	maxX = max(maxX, x[node]);
	minX = min(minX, x[node]);
	maxY = max(maxY, y[node]);
	minY = min(minY, y[node]);
	int perim = maxX - minX + maxY - minY;
	for (int i : adj[node]) {
		perim = max(perim, dfs(i, maxX, minX, maxY, minY));
	}
	return perim;
}

int main() {
	freopen("fenceplan.in", "r", stdin);
	freopen("fenceplan.out", "w", stdout);

	cin >> n >> m;

	x.resize(n);
	y.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	adj.resize(n, vector<int>(0));
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	visited.resize(n);
	int minPerim = INT_MAX;
	for (int i = 0; i < n; i++) {
		// visited nodes have to be skipped here as well, to prevent
		// line 13 from returning 0 as a perimeter!
		if (!visited[i]) {
			minPerim = min(minPerim, dfs(i, 0, 10e8, 0, 10e8));
		}
	}

	cout << minPerim * 2;
	return 0;
}
