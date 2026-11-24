#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, k, l = 0, r, coun = 0;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end(), greater<int>());
    coun = v[0];

    for (r = 1; r < n; r++) {
        if (v[l] - v[r] >= k) {
            l++;
        } else {
            coun += v[r];
        }
    }
    cout << coun << "\n";
}