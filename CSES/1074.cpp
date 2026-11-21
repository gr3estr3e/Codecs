#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, ans = 0, med;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p.begin(), p.end());
    med = p[n/2];
    for (int i = 0; i < n; i++) {
        ans += abs(p[i] - med);
    }
    cout << ans << "\n";
}