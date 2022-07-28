#include <algorithm>
#include <cassert>
#include <bitset>
#include <deque>
#include <iostream>
#include <climits>
#include <list>
#include <map>
#include <cmath>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

#define dbg(x) cout<<(#x)<<": "<<(x)<<endl
#define dbglp(x) cout<<(#x)<<":"<<endl;for(auto z:x)cout<<z<<" ";cout<<endl
typedef long long ll;

int n;
vector<vector<bool>> grid;
vector<vector<bool>> visited;

vector<vector<int>> area;
vector<vector<int>> perim;
void ff(int x, int y, int homeX, int homeY) {
	if (x < 0 || x >= n || y < 0 || y >= n) return;
	if (!grid[x][y]) return;
	if (visited[x][y]) return;
	visited[x][y] = true;

	area[homeX][homeY]++;
	perim[homeX][homeY] += 4;
	if (x + 1 < n) if (grid[x + 1][y]) perim[homeX][homeY]--;
	if (x - 1 >= 0) if (grid[x - 1][y]) perim[homeX][homeY]--;
	if (y + 1 < n) if (grid[x][y + 1]) perim[homeX][homeY]--;
	if (y - 1 >= 0) if (grid[x][y - 1]) perim[homeX][homeY]--;
	ff(x + 1, y, homeX, homeY) ;
	ff(x - 1, y, homeX, homeY);
	ff(x, y + 1, homeX, homeY);
	ff(x, y - 1, homeX, homeY);
}

int main() {
	freopen("perimeter.in", "r", stdin);
	freopen("perimeter.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	grid.resize(n, vector<bool>(n));
	visited.resize(n, vector<bool>(n));
	area.resize(n, vector<int>(n));
	perim.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			grid[i][j] = (s.at(j) == '#' ? true : false);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) ff(i, j, i, j);
	}

	int maxArea = 0, minPerim = 1e9;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (area[i][j] > maxArea) {
				maxArea = area[i][j];
				minPerim = perim[i][j];
			}
			if (area[i][j] == maxArea) {
				minPerim = min(minPerim, perim[i][j]);
			}
		}
	}

	cout << maxArea << " " << minPerim;
	return 0;
}
