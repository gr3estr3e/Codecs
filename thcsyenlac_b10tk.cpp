#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, l, r, mid, curr, ans = 0;
    cin >> n;
    vector<int> h(n); for (int i = 0; i < n; i++) cin >> h[i];
    cin >> m;

    l = 0, r = 1e9;
    while (l<=r) {
        mid = (l+r)/2, curr = 0;
        for (int i = 0; i < n; i++) if (h[i] > mid) curr += h[i] - mid;
       if (curr >= m) {
            l = mid + 1;
            ans = max(mid, ans);
        } else {
            r = mid - 1;
        }
    }
    cout << ans << "\n";
}