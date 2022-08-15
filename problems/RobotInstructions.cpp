#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct hsh {
	size_t operator() (const pair<ll, ll> &p) const {
		return p.first * 100000000 + p.second;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, xg, yg;
	cin >> n >> xg >> yg;
	vector<pair<ll, ll>> ains(n / 2);
	vector<pair<ll, ll>> bins((n + 1) / 2);
	for (ll i = 0; i < n / 2; i++) {
		ll a, b;
		cin >> a >> b;
		ains[i] = {a, b};
	}
	for (ll i = n / 2; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		bins[i - n / 2] = {a, b};
	}

	vector<ll> ks(n + 1);
	unordered_map<pair<ll, ll>, map<ll, ll>, hsh> acoords;
	// vector stores the number of instructions in each subset of dest
	for (ll i = 0; i < (1 << n / 2); i++) {
		pair<ll, ll> dest = {0, 0};
		ll instr = 0;
		for (ll j = 0; j < n / 2; j++) {
			if (i & (1 << j)) {
				dest.first += ains[j].first;
				dest.second += ains[j].second;
				instr++;
			}
		}
		acoords[dest][instr]++;
	}
	// check against b subsets
	for (ll i = 0; i < (1 << (n + 1) / 2); i++) {
		pair<ll, ll> dest = {0, 0};
		ll instr = 0;
		for (ll j = 0; j < (n + 1) / 2; j++) {
			if (i & (1 << j)) {
				dest.first += bins[j].first;
				dest.second += bins[j].second;
				instr++;
			}
		}
		// add list of a instructions with b instructions
		for (auto j : acoords[{xg - dest.first, yg - dest.second}]) {
			ks[j.first + instr] += j.second;
		}
	}

	for (ll i = 1; i < n + 1; i++) cout << ks[i] << "\n";
	return 0;
}
