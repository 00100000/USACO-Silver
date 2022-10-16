#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

int n, k;
vector<int> x;

bool valid(int r) {
	int maxX = 0;
	int left = k;
	int i = 0;
	while (i < n) {
		maxX = x[i] + r * 2;
		left--;
		while (i < n && x[i] <= maxX) i++;
	}
	return left >= 0;
}

int main() {
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;
	x.resize(n);
	for (int i = 0; i < n; i++) cin >> x[i];
	sort(x.begin(), x.end());

	int l = 0, r = 1e9;
	while (l < r) {
		int mid = (l + r) / 2;
		if (valid(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}

	cout << l;
	return 0;
}
