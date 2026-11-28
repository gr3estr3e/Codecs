#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1), pref(n+1, 0);
    for (int i = 1; i<=n;i++) {
        cin >> a[i];
        pref[i] = pref[i-1] + a[i];
    }
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        cout << pref[b] - pref[a-1] << "\n";
    }
}