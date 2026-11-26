#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s, l, r, maxl = 0, ansl, ansr, mlength; cin >> n >> s;
    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];

    l = 0, r = 0, mlength = n+1, ansr=0, ansl=0;
    while (r < n) {
        maxl += a[r];
        while (maxl >= s && l <= r) {
            if (r-l+1 < mlength) {
                mlength = min(mlength, r-l+1);
                ansl = l;
                ansr = r;
            }
            maxl-=a[l];
            l++;
        }
        r++;
    }

    if (mlength > n) {
        cout << "0 0" << "\n";
        return 0;
    }
    cout << ansl+1 << " " << ansr+1 << "\n";
}