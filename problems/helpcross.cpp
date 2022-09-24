#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

bool cmp(const pair<int, int> &a, const pair<int, int> &b) { return a.second < b.second; }

int main() {
	freopen("helpcross.in", "r", stdin);
	freopen("helpcross.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int c, n;
	cin >> c >> n;
	map<int, int> t;
	vector<pair<int, int>> ab(n);
	for (int i = 0; i < c; i++) {
		int temp;
		cin >> temp;
		t[temp]++;
	}
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		ab[i] = {a, b};
	}
	// sort by end of cow crossing intervals
	sort(ab.begin(), ab.end(), cmp);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		// binary search for lowest chicken in cow's range
		auto up = t.lower_bound(ab[i].first);
		if (up != t.end()) {
			// if no chicken is in this cow's range
			if (up->first > ab[i].second) continue;
			// cross with chicken
			if (up->second > 0) {
				up->second--;
				cnt++;
			}
			// remove used chickens
			if (up->second == 0) t.erase(up->first);
		}
	}

	cout << cnt;
	return 0;
}
