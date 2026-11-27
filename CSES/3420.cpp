#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, l, r, ans = 0;
    cin >> n;
    vector<int> x(n);
    map<int, int> freq;
    for (int i = 0; i < n; i++) cin >> x[i];

    l = 0, r = 0;
    while (r < n) {
        if (freq.find(x[r]) != freq.end()) {
            l = max(l, freq[x[r]]+1);
        }
        freq[x[r]] = r;
        ans += (r-l+1);
        r++;
    }
    cout << ans << "\n";
}