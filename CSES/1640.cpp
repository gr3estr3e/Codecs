#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, l, r;
    cin >> n >> x;
    vector<pair<int, int>> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i].first, a[i].second = i;
    sort(a.begin(), a.end());

    l = 1, r = n;
    while (l < r) {
        if (a[l].first + a[r].first == x) {
            cout << a[l].second << " " << a[r].second << "\n";
            return 0;
        } else if (a[l].first + a[r].first < x) {
            l++;
        } else {
            r--;
        }
    }
    cout << "IMPOSSIBLE" << "\n";
    // cout << ansl << " " << ansr << "\n";
}