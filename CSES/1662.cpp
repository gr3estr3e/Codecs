#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int n, l, r, ans = 0; cin >> n;
    vector<int> a(n+1), pref(n+1, 0); for (int i = 1; i <= n; i++) cin >> a[i], pref[i] = pref[i-1] + a[i];

    l = 0, r = 0;
    while (r <= n) {
        if (pref[r] - pref[l] % n == 0) {
            l++;
            ans++;
            r++;
        } else {
            r++;
        }
    }
    cout << ans << endl;
}