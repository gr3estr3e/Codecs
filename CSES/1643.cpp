#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n, ans = INT_MIN; cin >> n;
	vector<int> a(n+1), pref(n+1, 0), prefm(n+1, 0); for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pref[i] = pref[i-1] + a[i];
		prefm[i] = min(prefm[i-1],  pref[i]);
	}
	for (int i = 1; i <= n; i++) {
		ans = max(ans, pref[i] - prefm[i-1]);
	}
	cout << ans << "\n";
}