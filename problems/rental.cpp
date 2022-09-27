#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include <algo/debug.h>
#endif

typedef long long ll;

bool cmpDesc(const int& a, const int& b) { return a > b; }
bool cmpPriceDesc(const pair<int, int>& a, const pair<int, int>& b) { return a.second > b.second; }

int main() {
	freopen("rental.in", "r", stdin);
	freopen("rental.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, r;
	cin >> n >> m >> r;
	vector<int> c(n);
	for (int i = 0; i < n; i++) cin >> c[i];
	vector<pair<int, int>> sell(m);
	for (int i = 0; i < m; i++) {
		int q, p;
		cin >> q >> p;
		sell[i] = {q, p};
	}
	vector<int> rent(r);
	for (int i = 0; i < r; i++) cin >> rent[i];
	sort(c.begin(), c.end(), cmpDesc);
	sort(sell.begin(), sell.end(), cmpPriceDesc);
	sort(rent.begin(), rent.end(), cmpDesc);
	// it's always optimal to sell milk from cows that produce a lot at a higher price
	// and rent away cows that don't produce much, so calculate how much money farmer
	// john gets from each choice on a cow
	vector<ll> sellPrice(n);
	vector<ll> rentPrice(n);
	for (int i = 0, j = 0; i < n; i++) {
		int milk = c[i];
		// sell all milk to highest paying stores
		while (j < m && milk > 0) {
			sellPrice[i] += min(sell[j].first, milk) * sell[j].second;
			int temp = milk;
			milk -= sell[j].first;
			sell[j].first -= temp;
			// switch to a new store
			if (sell[j].first <= 0) j++;
		}
	}
	for (int i = n - 1, j = 0; i >= 0 && j < r; i--, j++) rentPrice[i] = rent[j];
	// always choose the option that gives the better price
	ll best = 0;
	for (int i = 0; i < n; i++) {
		best += sellPrice[i] > rentPrice[i] ? sellPrice[i] : rentPrice[i];
	}

	cout << best;
	return 0;
}
