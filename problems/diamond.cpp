#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

int main() {
	freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<int> d(n);
	vector<int> size(n);
	for (int i = 0; i < n; i++) cin >> d[i];
	sort(d.begin(), d.end());
	int l = 0, r = 0;
	for (; l < n; l++) {
		while (r < n && d[r] <= d[l] + k) r++;
		size[l] = r - l;
	}
	// both ranges must be disjoint, otherwise you can just move the higher range up
	vector<int> maxRight(n + 1);
	// find best disjoint range to pair with any given range from the left
	for (int i = n - 1; i >= 0; i--) maxRight[i] = max(maxRight[i + 1], size[i]);
	int inclusive = 0;
	for (int i = 0; i < n; i++) inclusive = max(inclusive, size[i] + maxRight[i + size[i]]);

	cout << inclusive;
	return 0;
}
