#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int n, x, ans = 0; cin >> n >> x;
	vector<int> a(n+1), prefix(n+1, 0); for (int i = 1; i <= n; i++) cin >> a[i], prefix[i] = prefix[i-1] + a[i];
	map<int, int> counters;
	counters[0] = 1;

	for (int i = 1; i <= n; i++) {
		ans += counters[prefix[i]-x];
		counters[prefix[i]]++;
	}
	cout << ans << "\n";

}