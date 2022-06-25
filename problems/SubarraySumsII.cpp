#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n >> x;
	// prefix sums
	vector<long long> sum(n);
	int temp;
	cin >> temp;
	sum[0] = temp;
	for (int i = 1; i < n; i++) {
		cin >> temp;
		sum[i] = sum[i - 1] + temp;
	}
	// unique prefixes
	map<long long, int> m;
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		// track each prefix
		m[sum[i]]++;
		// if an old prefix is the difference between this prefix and the target,
		// the target can be made with the prefix - the old prefix
		if (m[sum[i] - x] > 0) {
			cnt += m[sum[i] - x];
		// just in case the subarray = x
		}
		if (sum[i] == x /* 0 target is an extremely obnoxious edgecase */ && x != 0) {
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}
