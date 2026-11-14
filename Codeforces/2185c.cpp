#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, pre = -1e9-7, cnt = 1, mxcnt = 1; cin >> n;
		set<int> a;
		for (int i = 0, b; i < n; i++) {
			cin >> b;
			a.insert(b);
		}
		for (int i : a) {
			if (pre + 1 == i) cnt++;
			else cnt = 1;
			pre = i;
			mxcnt = max(mxcnt, cnt);
		}
		cout << mxcnt << "\n";

	}
}