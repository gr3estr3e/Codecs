#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k, l = 0, r = 0, m, cans, curr_w;
    bool check = true;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i], l = max(l, a[i]), r += a[i];
    // sort(a.begin(), a.end());
    while (l < r) {
        m = l + ((r-l)/2);
        curr_w = 0, cans = 1;
        for (int i = 0; i < n; i++) {
            if (curr_w + a[i] <= m) {
                curr_w+= a[i];
            } else {
                cans++;
                curr_w = a[i];
            }
        }
        if (cans <= k) check = true;
        else check = false;
        if (check == true) r = m;
        else l = m+1;
    }
    cout << l << "\n";
}