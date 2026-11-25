#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, d, r, l, ans = 0;
    cin >> n >> d;
    if (d == 0) {
        cout << 0 << "\n";
        return 0;
    }
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    sort(h.begin(), h.end());
    l = 0, r = 0;
    while (l < n && r < n) {
        if (r < n &&h[r] - h[l] < d) r++;
        if (r < n && h[r] - h[l] == d) {
            r++;
            ans++;
        }
        if (r < n && h[r] - h[l] > d) l++;
    }
    cout << ans << "\n";
}