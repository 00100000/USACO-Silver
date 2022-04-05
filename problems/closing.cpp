#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

vector<bool> visited;
vector<vector<int> > path;
unordered_set<int> closed;

void dfs(int b) {
	if (visited[b]) return;
	// if barn is closed, don't visit
	if (closed.find(b) != closed.end()) return;
	visited[b] = true;
	for (int i : path[b]) {
		dfs(i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	// construct adjacency list
	path.resize(n);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		path[a].push_back(b);
		path[b].push_back(a);
	}
	// solve
	visited.resize(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) visited[j] = false;
		// dfs on first unclosed barn
		for (int j = 0; j < n; j++) {
			if (closed.find(j) == closed.end()) {
				dfs(j);
				break;
			}
		}
		// check if visited all unclosed barns
		bool empty = true;
		for (int j = 0; j < n; j++) {
			if (closed.find(j) == closed.end() && !visited[j]) {
				empty = false;
				break;
			}
		}
		if (empty) {
			cout << "YES";
		} else {
			cout << "NO";
		}
		cout << "\n";
		// close next barn
		int at;
		cin >> at;
		at--;
		closed.insert(at);
	}

	return 0;
}
