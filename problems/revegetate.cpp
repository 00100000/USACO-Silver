#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

bool valid = true;
vector<vector<pair<int, char>>> adj;
vector<bool> color;
vector<bool> vis;

void dfs(int node, bool lastColor, char lastEdge) {
	if (vis[node]) {
		// verify that there are no conflicting edges
		if (lastEdge == 'D' && color[node] == lastColor) valid = false;
		if (lastEdge == 'S' && color[node] != lastColor) valid = false;
		return;
	}
	vis[node] = true;
	color[node] = (lastEdge == 'S' ? lastColor : !lastColor);
	for (auto i : adj[node]) dfs(i.first, color[node], i.second);
}

int main() {
	freopen("revegetate.in", "r", stdin);
	freopen("revegetate.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	adj.resize(n);
	color.resize(n);
	vis.resize(n);
	for (int i = 0; i < m; i++) {
		char c;
		int a, b;
		cin >> c >> a >> b;
		a--;
		b--;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	// color in graph and count components
	int components = 0;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			dfs(i, true, 'S');
			components++;
		}
	}
	// each component doubles the number of ways the grass can be planted, because the
	// 2 seed types can be "flipped" in every component
	if (valid) {
		cout << 1;
		for (int i = 0; i < components; i++) cout << 0;
	} else {
		cout << 0;
	}
	return 0;
}
