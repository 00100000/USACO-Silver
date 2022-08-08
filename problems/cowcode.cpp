#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	freopen("cowcode.in", "r", stdin);
	freopen("cowcode.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	ll n;
	cin >> s >> n;
	n--;
	// find smallest number that is a result of s.size() * 2^x larger than n
	ll len = (ll)s.size();
	while (len < n) len <<= 1;

	while (n >= (int)s.size()) {
		while (len + 1 > n) {
			len >>= 1;
			// edgecase: len lines up to n
			if (len == n) {
				n = len + 1;
				break;
			}
		}
		n -= len + 1;
	}

	cout << s.at(n);
	return 0;
}
