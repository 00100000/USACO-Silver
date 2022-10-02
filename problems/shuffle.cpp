#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

vector<vector<int>> backward;
vector<bool> vis;

void dfs(int node) {
	if (vis[node]) return;
	vis[node] = true;
	for (auto i : backward[node]) {
		dfs(i);
	}
}

int main() {
	freopen("shuffle.in", "r", stdin);
	freopen("shuffle.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> adj(n);
	backward.resize(n);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		a--;
		adj[i] = a;
		backward[a].push_back(i);
	}
	// if the position is in a cycle, a cow will always occupy it
	vector<bool> inCycle(n);
	vis.resize(n);
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			int a = i, b = i;
			do {
				a = adj[a];
				b = adj[adj[b]];
			} while (a != b);
			// mark off entire cycle
			b = a;
			dfs(i);
			do {
				vis[a] = true;;
				inCycle[a] = true;
				a = adj[a];
			} while (a != b);
			// close off "tail end" that leads into cycle
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) if (inCycle[i]) cnt++;

	cout << cnt;
	return 0;
}
