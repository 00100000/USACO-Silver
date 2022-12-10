#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

vector<vector<pair<int, int>>> adj;
vector<bool> vis;

int dfs(int node, int rel, int mindist) {
	if (vis[node]) return 0;
	vis[node] = true;
	int sum = mindist >= rel;
	for (auto i : adj[node]) {
		sum += dfs(i.first, rel, min(mindist, i.second));
	}
	return sum;
}

int main() {
	freopen("mootube.in", "r", stdin);
	freopen("mootube.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	cin >> n >> q;
	adj.resize(n);
	vis.resize(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v, r;
		cin >> u >> v >> r;
		u--;
		v--;
		adj[u].push_back({v, r});
		adj[v].push_back({u, r});
	}

	for (int i = 0; i < q; i++) {
		int k, v;
		cin >> k >> v;
		v--;
		// overcounts by 1 because of initial mindist
		cout << dfs(v, k, 1e9 + 1) - 1<< '\n';
		vis.clear();
		vis.resize(n);
	}

	return 0;
}
