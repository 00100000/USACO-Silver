#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

struct Log {
	int day, ID, change;
};

bool cmp(const Log& a, const Log& b) { return a.day < b.day; }

int main() {
	freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, g;
	cin >> n >> g;
	vector<Log> l(n);
	map<int, int> m;
	multiset<int> vals;
	for (int i = 0; i < n; i++) {
		cin >> l[i].day >> l[i].ID >> l[i].change;
		// check map to prevent repeats
		if (!m[l[i].ID]) vals.insert(g);
		m[l[i].ID] = g;
	}
	sort(l.begin(), l.end(), cmp);

	int change = 0;
	int maxVal = g, maxCnt = n;
	for (int i = 0; i < n; i++) {
		int prevVal = m[l[i].ID];
		m[l[i].ID] += l[i].change;
		int newVal = m[l[i].ID];
		vals.erase(vals.find(prevVal));
		vals.insert(newVal);
		// already a max value cow
		if (prevVal == maxVal) {
			// losing value
			if (newVal < maxVal) {
				maxVal = *vals.rbegin();
				// if the most valuable cow was the only cow at that value, and it stays
				// the most valuable
				int newCnt = vals.count(newVal);
				if (newCnt != 1 || newVal != maxVal) change++;
				maxCnt = vals.count(maxVal);
			// gaining value
			} else {
				// if the most valuable cow was the only cow at that value, and it stays
				// the most valuable
				if (maxCnt != 1 || prevVal != maxVal) change++;
				maxCnt = 1;
				maxVal = newVal;
			}
		// not a max value cow
		} else {
			// becoming another max value
			if (newVal == maxVal) {
				change++;
				maxCnt++;
			// overtaking the other max value cows
			} else if (newVal > maxVal) {
				change++;
				maxCnt = 1;
				maxVal = newVal;
			}
		}
	}

	cout << change;
	return 0;
}
