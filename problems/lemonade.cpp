#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("lemonade.in", "r", stdin);
	freopen("lemonade.out", "w", stdout);

	int n;
	cin >> n;

	vector<int> cow(n);
	for (int i = 0; i < n; i++) cin >> cow[i];
	sort(cow.begin(), cow.end());

	for (int i = n - 1, j = 0; i >= 0; i--) {
		if (j > cow[i]) {
			cout << j;
			return 0;
		} else {
			j++;
		}
	}

	cout << n;
	return 0;
}
