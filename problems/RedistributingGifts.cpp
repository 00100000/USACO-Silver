#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#endif

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> 
	vector<vector<int>> adj(n);
	vector<vector<bool>> matrix(n, vector<bool>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			temp--;
			adj[i].push_back(temp);
			matrix[i][temp] = true;
			// get rid of gifts i can never get
			if (temp == i) {
				j++;
				for (; j < n; j++) cin >> temp;
				break;
			}
		}
	}
	// floyd-warshall
	vector<vector<bool>> possible(n, vector<bool>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) possible[i][j] = true;
			else if (matrix[i][j]) possible[i][j] = true;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				possible[j][k] = possible[j][k] || (possible[j][i] && possible[i][k]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (int)adj[i].size(); j++) {
			if (possible[adj[i][j]][i]) {
				cout << adj[i][j] + 1 << "\n";
				break;
			}
		}
	}

	return 0;
}
