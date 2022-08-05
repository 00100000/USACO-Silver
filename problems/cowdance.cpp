#include <bits/stdc++.h>
using namespace std;

int n, tmax;
vector<int> d;

int timeAt(int k) {
	vector<int> dance(k);
	for (int i = 0; i < k; i++) dance[i] = d[i];

	for (int i = k; i < n; i++) {
		int minSeen = INT_MAX;
		int mindex = 0;
		for (int j = 0; j < k; j++) {
			if (dance[j] < minSeen) {
				minSeen = dance[j];
				mindex = j;
			}
		}
		dance[mindex] += d[i];
	}
	int dmax = 0;
	for (int i = 0; i < k; i++) dmax = max(dmax, dance[i]);
	return dmax;
}

int main() {
	freopen("cowdance.in", "r", stdin);
	freopen("cowdance.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> tmax;
	d.resize(n);
	for (int i = 0; i < n; i++) cin >> d[i];
	// binary search for k
	int l = 1, r = n;
	while (l <= r) {
		int mid = (l + r) / 2;
		int tAt = timeAt(mid);
		if (tAt == tmax || (tAt < tmax && timeAt(mid - 1) > tmax)) {
			cout << mid;
			break;
		}
		if (timeAt(mid) > tmax) l = mid;
		else r = mid;
	}

	return 0;
}
