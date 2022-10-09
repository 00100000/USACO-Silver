#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}

int main() {
	freopen("mountains.in", "r", stdin);
	freopen("mountains.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	// mountain A blocks mountain B if the entire base of B is contained within mountain A
	vector<pair<int, int>> base(n);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		base[i].first = x - y;
		base[i].second = x + y;
	}
	sort(base.begin(), base.end(), cmp);

	int visible = n;
	int maxY = 0;
	for (int i = 0; i < n; i++) {
		if (maxY >= base[i].second) {
			visible--;
		} else {
			maxY = base[i].second;
		}
	}

	cout << visible;
	return 0;
}
