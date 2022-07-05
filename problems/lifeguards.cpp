#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits.h>
#include <utility>
#include <vector>
using namespace std;

int main() {
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> guards(n);
	for (int i = 0; i < n; i++) {
		cin >> guards[i].first >> guards[i].second;
	}
	sort(guards.begin(), guards.end());
	// find how much time each guard overlaps with other guards
	vector<long long> overlap(n);
	overlap[0] = guards[0].second - guards[1].first;
	overlap[n - 1] = guards[n - 2].second - guards[n - 1].first;
	// track the leftmost bound
	int leftmost = 0;
	for (int i = 1; i < n - 1; i++) {
		overlap[i] += max(0, guards[i].second - guards[i + 1].first);
		overlap[i] += max(0, guards[i - 1].second - guards[i].first);
		// this means this guard's time is completely surrounded
		// and it can be removed for 0 time loss
		if (leftmost > guards[i].second) {
			// this will set its overlap to its size, making its
			// space 0
			overlap[i] = guards[i].second - guards[i].first;
		}
		leftmost = max(leftmost, guards[i].second);
	}
	// find the amount of unique space each lifeguard takes up
	// unique space = total space - overlap
	vector<long long> space(n);
	for (int i = 0; i < n; i++) {
		space[i] = guards[i].second - guards[i].first - overlap[i];
		// an overlap greater than 0 means it is completely surrounded
		if (space[i] < 0) space[i] = 0;
	}

	long long minspace = LONG_MAX;
	for (int i = 0; i < n; i++) {
		if (minspace > space[i]) {
			minspace = space[i];
		}
	}

	int sum = 0;
	leftmost = 0;
	for (int i = 0; i < n; i++) {
		sum += max(0, guards[i].second - max(leftmost, guards[i].first));
		leftmost = max(leftmost, guards[i].second);
	}

	cout << sum - minspace;
	return 0;
}
