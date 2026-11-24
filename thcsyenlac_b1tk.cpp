#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, c, l, r, m, ans = 0;
    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    l = 0; r = n-1;
    m = l+r/2;
    while (l < r) {
        int curr = a[l] + a[r];
        if (curr <= c) {
            ans = max(ans, curr);
            l++;
        } else {
            r--;
        }
    }
    cout << ans << "\n"; 
}