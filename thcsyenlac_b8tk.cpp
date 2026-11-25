#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, s, ans, curr, r, l;
    cin >> n >> s;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    l = 1, ans = 0, curr = 0;
    for (r = 1; r <= n; r++) {
        curr+=a[r];
        while (l <= r && curr > s) {
            curr-=a[l];
            l++;
        }
        ans += (r-l+1);
    }
    cout << ans << "\n";
}