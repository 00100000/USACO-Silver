#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);

	int n;
	cin >> n;
	// prefix sum each move
	vector<int> hSum(n);
	vector<int> pSum(n);
	vector<int> sSum(n);
	for (int i = 0; i < n; i++) {
		char move;
		cin >> move;
		switch (move) {
			case 'H':
				hSum[i]++;
				break;
			case 'P':
				pSum[i]++;
				break;
			case 'S':
				sSum[i]++;
				break;
		}
		if (i < n - 1) {
			hSum[i + 1] = hSum[i];
			pSum[i + 1] = pSum[i];
			sSum[i + 1] = sSum[i];
		}
	}
	// simulate switching from h -> p, h -> s, etc... at any point in time
	int maxSwitch = 0;
	for (int i = 0; i < n; i++) {
		maxSwitch = max(maxSwitch, hSum[i] + pSum[n - 1] - pSum[max(i - 1, 0)]);
		maxSwitch = max(maxSwitch, hSum[i] + sSum[n - 1] - sSum[max(i - 1, 0)]);
		maxSwitch = max(maxSwitch, pSum[i] + hSum[n - 1] - hSum[max(i - 1, 0)]);
		maxSwitch = max(maxSwitch, pSum[i] + sSum[n - 1] - sSum[max(i - 1, 0)]);
		maxSwitch = max(maxSwitch, sSum[i] + hSum[n - 1] - hSum[max(i - 1, 0)]);
		maxSwitch = max(maxSwitch, sSum[i] + pSum[n - 1] - pSum[max(i - 1, 0)]);
	}

	cout << maxSwitch;
	return 0;
}
