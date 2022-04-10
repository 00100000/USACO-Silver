#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	vector<int> cCnt(s.size());
	vector<int> oCnt(s.size());
	vector<int> wCnt(s.size());
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'C') cCnt[i]++;
		if (s[i] == 'O') oCnt[i]++;
		if (s[i] == 'W') wCnt[i]++;
		cCnt[i + 1] += cCnt[i];
		oCnt[i + 1] += oCnt[i];
		wCnt[i + 1] += wCnt[i];
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		int cq = cCnt[b - 1] - (a > 1 ? cCnt[a - 2] : 0);
		int oq = oCnt[b - 1] - (a > 1 ? oCnt[a - 2] : 0);
		int wq = wCnt[b - 1] - (a > 1 ? wCnt[a - 2] : 0);
		if (wq % 2 == oq % 2 && wq % 2 > cq % 2) {
			cout << 'Y';
		} else if (cq % 2 > wq % 2 && cq % 2 > oq % 2) {
			cout << 'Y';
		} else {
			cout << 'N';
		}
	}

	return 0;
}
