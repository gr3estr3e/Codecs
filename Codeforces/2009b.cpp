#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			string a;
			cin >> a;
			for (int j = 0; j < 4; j++) {
				if (a[j] == '#') {
					ans.push_back(j+1);
				}
			}
		}
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < n; i++) {
			cout << ans[i] << (i == n-1 ? "" : " ");
		}
		cout << "\n";
	}
}