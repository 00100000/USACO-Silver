#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<bool> vis;
vector<vector<ll>> undirected;
// mark an entire connected component as solved
void check(ll node) {
	if (vis[node]) return;
	vis[node] = true;
	for (auto i : undirected[node]) check(i);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;
	ll sum = 0;
	vector<ll> adj(n);
	vector<ll> moos(n);
	undirected.resize(n);
	vis.resize(n);
	for (ll i = 0; i < n; i++) {
		cin >> adj[i];
		cin >> moos[i];
		sum += moos[i];
		adj[i]--;
		undirected[i].push_back(adj[i]);
		undirected[adj[i]].push_back(i);
	}

	for (ll i = 0; i < n; i++) {
		// find the cycle in the largest connected component
		if (!vis[i]) {
			ll a = adj[i], b = adj[adj[i]];
			while (a != b) {
				a = adj[a];
				b = adj[adj[b]];
			}
			ll minMoos = LONG_MAX;
			a = adj[a];
			while (a != b) {
				minMoos = min(minMoos, moos[a]);
				a = adj[a];
			}
			minMoos = min(minMoos, moos[b]);
			sum -= minMoos;

			check(i);
		}
	}

	cout << sum;
	return 0;
}
