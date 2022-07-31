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

int main() {
	freopen("bgm.in", "r", stdin);
	freopen("bgm.out", "w", stdout);

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll n;
	cin >> n;
	map<char, map<ll, ll>> val;
	for (ll i = 0; i < n; i++) {
		char c;
		ll v;
		cin >> c >> v;
		v %= 7;
		val[c][v]++;
	}

	ll cnt = 0;
	for (auto b : val['B']) {
		for (auto e : val['E']) {
			for (auto s : val['S']) {
				for (auto i : val['I']) {
					for (auto g : val['G']) {
						for (auto o : val['O']) {
							for (auto m : val['M']) {
								ll prod = (b.first + e.first + s.first + s.first + i.first + e.first) * (g.first + o.first + e.first + s.first) * (m.first + o.first + o.first);
								if (prod % 7 == 0) {
									cnt += b.second * e.second * s.second * i.second * g.second * o.second * m.second;
								}
							}
						}
					}
				}
			}
		}
	}

	cout << cnt;
	return 0;
}
