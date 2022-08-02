#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("highcard.in", "r", stdin);
	freopen("highcard.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<bool> elsie(2 * n);
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		temp--;
		elsie[temp] = true;
	}

	int points = 0;
	int bessie = 0;
	for (int i = 2 * n - 1; i >= 0; i--) {
		if (elsie[i]) {
			if (bessie > 0) {
				bessie--;
				points++;
			}
		} else {
			bessie++;
		}
	}
	
	cout << points;
	return 0;
}
