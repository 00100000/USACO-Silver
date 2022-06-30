#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, b;
	cin >> n >> k >> b;

	vector<int> sum(n);
	for (int i = 0; i < b; i++) {
		int broken;
		cin >> broken;
		broken--;
		sum[broken] = 1;
	}
	// prefix sums
	for (int i = 1; i < n; i++) {
		sum[i] += sum[i - 1];
	}

	int mindiff = 10e5;
	for (int i = 0; i < n - k; i++) {
		mindiff = min(mindiff, sum[i + k] - sum[i]);
	}

	cout << mindiff;
	return 0;
}
