#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

int main() {
	freopen("convention.in", "r", stdin);
	freopen("convention.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, c;
	cin >> n >> m >> c;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	// binary search on the wait time
	int l = 0, r = 1e9;
	while (l < r) {
		int mid = (l + r) / 2;
		// validate that wait time is possible
		int mLeft = m, cLeft = 0;
		int tArrive = 0;
		for (int i = 0; i < n; i++) {
			if (cLeft == 0 || a[i] - tArrive > mid) {
				mLeft--;
				cLeft = c;
				tArrive = a[i];
			}
			cLeft--;
		}
		if (mLeft > -1) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}

	cout << l;
	return 0;
}
