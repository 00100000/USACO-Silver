#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cout<<(#x)<<": "<<(x)<<endl
#define dbglp(x) cout<<(#x)<<":"<<endl;for(auto z:x)cout<<z<<" ";cout<<endl
typedef long long ll;

int n, m;
int rooms = 1;
vector<vector<bool>> lit;
vector<vector<bool>> vis;
map<pair<int, int>, vector<pair<int, int>>> sw;

void ff(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= n) return;
	if (!lit[x][y]) return;
	if (vis[x][y]) return;
	vis[x][y] = true;
	vector<pair<int, int>>& temp = sw[{x, y}];
	for (int i = 0; i < (int)temp.size(); i++) {
		if (!lit[temp[i].first][temp[i].second]) {
			lit[temp[i].first][temp[i].second] = true;
			rooms++;
			if (temp[i].first + 1 < n) if (vis[temp[i].first + 1][temp[i].second]) ff(temp[i].first, temp[i].second);
			if (temp[i].first - 1 >= 0) if (vis[temp[i].first - 1][temp[i].second]) ff(temp[i].first, temp[i].second);
			if (temp[i].second + 1 < n) if (vis[temp[i].first][temp[i].second + 1]) ff(temp[i].first, temp[i].second);
			if (temp[i].second - 1 >= 0) if (vis[temp[i].first][temp[i].second - 1]) ff(temp[i].first, temp[i].second);
		}
	}
	ff(x + 1, y);
	ff(x - 1, y);
	ff(x, y + 1);
	ff(x, y - 1);
}

int main() {
	freopen("lightson.in", "r", stdin);
	freopen("lightson.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> m;
	lit.resize(n, vector<bool>(n));
	vis.resize(n, vector<bool>(n));
	lit[0][0] = true;
	for (int i = 0; i < m; i++) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;
		x--;
		y--;
		a--;
		b--;
		sw[{x, y}].push_back({a, b});
	}
	ff(0, 0);

	cout << rooms;
	return 0;
}
