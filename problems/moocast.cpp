#include <cmath>
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int n;
vector<vector<bool>> adj;
vector<bool> visited;

int dfs(int node) {
	if (visited[node]) return 0;
	visited[node] = true;
	int sum = 1;
	for (int i = 0; i < n; i++) {
		if (adj[node][i]) {
			sum += dfs(i);
		}
	}
	return sum;
}

int main() {
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	vector<int> x(n);
	vector<int> y(n);
	vector<int> power(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i] >> power[i];
	}

	adj.resize(n, vector<bool>(n));
	visited.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			// distance formula
			// POTENTIAL ISSUE WITH USING INTS INSTEAD OF DOUBLES
			if (sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2)) < power[i]) {
				adj[i][j] = true;
			} else {
				adj[i][j] = false;
			}
		}
	}

	int maxPath = 0;
	for (int i = 0; i < n; i++) {
		maxPath = max(maxPath, dfs(i));
		// reset visited
		for (int j = 0; j < n; j++) visited[j] = false;
	}

	cout << maxPath;
	return 0;
}
