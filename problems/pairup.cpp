#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("pairup.in", "r", stdin);
	freopen("pairup.out", "w", stdout);

	int n;
	cin >> n;

	vector<pair<int, int>> group(n);
	for (int i = 0; i < n; i++) {
		int cnt, milk;
		cin >> cnt >> milk;
		group[i] = make_pair(milk, cnt);
	}
	sort(group.begin(), group.end());
	// two pointers
	int a = 0, b = n - 1;
	int aCnt = group[a].second, bCnt = group[b].second;
	int maxMilk = 0;
	while (a != b && a < n && b >= 0) {
		maxMilk = max(maxMilk, group[a].first + group[b].first);
		if (aCnt == bCnt) {
			a++;
			b--;
			aCnt = group[a].second;
			bCnt = group[b].second;
		} else if (aCnt > bCnt) {
			b--;
			aCnt -= bCnt;
			bCnt = group[b].second;
		} else if (aCnt < bCnt) {
			a++;
			bCnt -= aCnt;
			aCnt = group[a].second;
		}
	}

	cout << maxMilk;
	return 0;
}
