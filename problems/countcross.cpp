#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

int n;
int canVis = 0;
set<vector<int>> road;
vector<vector<bool>> grid;
vector<vector<bool>> vis;

bool valid(int x1, int y1, int x2, int y2) {
	vector<int> temp1 = {x1, y1, x2, y2};
	vector<int> temp2 = {x2, y2, x1, y1};
	return road.find(temp1) == road.end() && road.find(temp2) == road.end();
}

void ff(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n) return;
	if (vis[x][y]) return;
	vis[x][y] = true;
	if (grid[x][y]) canVis++;
	if (valid(x, y, x + 1, y)) ff(x + 1, y);
	if (valid(x, y, x - 1, y)) ff(x - 1, y);
	if (valid(x, y, x, y + 1)) ff(x, y + 1);
	if (valid(x, y, x, y - 1)) ff(x, y - 1);
}

int main() {
	freopen("countcross.in", "r", stdin);
	freopen("countcross.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int k, r;
	cin >> n >> k >> r;
	grid.resize(n, vector<bool>(n));
	for (int i = 0; i < r; i++) {
		vector<int> temp(4);
		for (int j = 0; j < 4; j++) {
			cin >> temp[j];
			temp[j]--;
		}
		road.insert(temp);
	}
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		grid[a][b] = true;
	}
	// ff each cow
	int distant = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j]) {
				// reset vars
				canVis = 0;
				vis.clear();
				vis.resize(n, vector<bool>(n));
				// floodfill
				ff(i, j);
				distant += k - canVis;
			}
		}
	}
	
	cout << distant / 2;
	return 0;
}
