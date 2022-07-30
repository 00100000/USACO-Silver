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
int acomp, bcomp;
vector<vector<int>> img;
vector<vector<bool>> vis;
set<int> colors;

bool ff(int x, int y, int ax, int ay, int bx, int by, int parColor) {
	if (x < ax || x > bx || y < ay || y > by) return false;
	if (vis[x][y]) return false;
	if (img[x][y] != parColor) return false;
	vis[x][y] = true;

	ff(x + 1, y, ax, ay, bx, by, parColor);
	ff(x - 1, y, ax, ay, bx, by, parColor);
	ff(x, y + 1, ax, ay, bx, by, parColor);
	ff(x, y - 1, ax, ay, bx, by, parColor);
	return true;
}

bool isPCL(int ax, int ay, int bx, int by) {
	// check that there are only 2 colors
	for (int i = ax; i <= bx; i++) {
		for (int j = ay; j <= by; j++) {
			colors.insert(img[i][j]);
		}
	}
	if (colors.size() != 2) return false;
	// check that the cow has a component with one color, and a component with multiple
	acomp = 0, bcomp = 0;
	int iterations = 0;
	for (auto x : colors) {
		for (int i = ax; i <= bx; i++) {
			for (int j = ay; j <= by; j++) {
				// check if color component exists
				if (ff(i, j, ax, ay, bx, by, x)) {
					if (iterations == 0) {
						acomp++;
					} else {
						bcomp++;
					}
				}
			}
		}
		iterations++;
	}
	// reset visited
	for (int i = ax; i <= bx; i++) {
		for (int j = ay; j <= by; j++) {
			vis[i][j] = false;
		}
	}
	if ((acomp + bcomp < 3) || (acomp == 1 && bcomp == 1) || (acomp != 1 && bcomp != 1)) return false;
	return true;
}

int main() {
	freopen("where.in", "r", stdin);
	freopen("where.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	img.resize(n, vector<int>(n));
	vis.resize(n, vector<bool>(n));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			img[i][j] = s.at(j) - 'A';
		}
	}
	// loop through top left "anchor" points: start of a PCL
	vector<vector<int>> PCLlist(0, vector<int>(4));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// loop through bottom right end points
			for (int k = i; k < n; k++) {
				for (int l = j; l < n; l++) {
					// check if that area is a PCL
					if (isPCL(i, j, k, l)) {
						vector<int> temp(4);
						temp[0] = i;
						temp[1] = j;
						temp[2] = k;
						temp[3] = l;
						PCLlist.push_back(temp);
					}
					colors.clear();
				}
			}
		}
	}
	// check for PCLs that are a subset of another PCL
	for (int i = 0; i < (int)PCLlist.size(); i++) {
		for (int j = 0; j < (int)PCLlist.size(); j++) {
			if (i != j) {
				// check if j is subset of i
				vector<int> iList = PCLlist[i];
				vector<int> jList = PCLlist[j];
				if (iList[0] <= jList[0] && iList[1] <= jList[1] && iList[2] >= jList[2] && iList[3] >= jList[3]) {
					PCLlist.erase(PCLlist.begin() + j);
					j--;
					if (i > j) i--;
				}
			}
		}
	}

	cout << PCLlist.size();
	return 0;
}
