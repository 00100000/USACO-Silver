#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("homework.in", "r", stdin);
	freopen("homework.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	int sum = 0;
	vector<int> gr(n);
	vector<int> freq(10001);
	for (int i = 0; i < n; i++) {
		cin >> gr[i];
		sum += gr[i];
		freq[gr[i]]++;
	}

	int minInd = 0;
	// calculate every value of k
	vector<double> avg(n - 1);
	for (int i = 0; i < n - 1; i++) {
		// get minInd to the minimum value
		while (freq[minInd] == 0) minInd++;
		avg[i] = (double)(sum - minInd) / (double)(n - i - 1);
		freq[gr[i]]--;
		sum -= gr[i];
	}
	// ignore avg[0] because k != 0
	double maxAvg = 0;
	for (int i = 1; i < n - 1; i++) {
		if (avg[i] > maxAvg) maxAvg = avg[i];
	}

	for (int i = 1; i < n - 1; i++) {
		if (avg[i] == maxAvg) cout << i << "\n";
	}
	return 0;
}
