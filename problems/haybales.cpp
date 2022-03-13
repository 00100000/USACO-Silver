#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);

	int n, q;
	cin >> n >> q;

	vector<int> bales(n);
	for (int i = 0; i < n; i++) cin >> bales[i];
	sort(bales.begin(), bales.end());

	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		// binary search each query
		int aPos = 0, bPos = 0;

		int l = 0, r = n - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			// checked entire array
			if (a <= bales[mid] && (mid == 0 || a > bales[mid - 1])) {
				aPos = mid;
				break;
			} else if (bales[mid] > a) {
				r = mid - 1;
			} else if (bales[mid] < a) {
				l = mid + 1;
			}
		}
		l = 0, r = n - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (b >= bales[mid] && (mid == n - 1 || b < bales[mid + 1])) {
				bPos = mid + 1;
				break;
			} else if (b < bales[mid]) {
				r = mid - 1;
			} else if (b > bales[mid]) {
				l = mid + 1;
			}
		}
		if (a >= bales[n - 1]) aPos = n;
		if (b <= bales[0]) bPos = 0;
		cout << bPos - aPos << "\n";
	}

	return 0;
}
