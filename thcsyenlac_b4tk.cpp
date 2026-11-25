#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, left, right, ansalt = 0, ans, x = 0, mid;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i], x = max(x, a[i]);
    // sort(a.begin(), a.end());

    left = 1, right = 1e9;
    while (left <= right) {
        ans = 0;
        mid = (left+right)/2;
        for (int i = 0; i < n; i++) ans += a[i]/mid;
        if (ans >= k) {
            ansalt = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << ansalt << "\n";
}