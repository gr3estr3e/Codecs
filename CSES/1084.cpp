#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, m, k, l, r, counter = 0;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a.begin(), a.end()), sort(b.begin(), b.end());

    l = 0, r = 0;
    while (l < a.size() && r < b.size()) {
        if (a[l] < b[r]-k) {
            l++;
        } else if (a[l] > b[r]+k) {
            r++;
        } else {
            counter++;
            l++;
            r++;
        }
    }
    cout << counter << "\n";
}