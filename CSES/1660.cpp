#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x, l, r, kounts = 0, curr; cin >> n >> x;
    vector<int> k(n); for (int i = 0; i < n; i++) cin >> k[i];
    map<int, int> indexes;

    l = 0, r = 0, curr = k[0];
    while (r < n) {
        if (curr > x) {
            curr -= k[l];
            l++;
        } else if (curr < x) {
            r++;
            curr += k[r];
        } else {
            kounts++;
            curr -= k[l];
            l++;
        }
    }
    cout << kounts << "\n";
}