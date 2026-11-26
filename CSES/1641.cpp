#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;

    sort(a.begin(), a.end());

    for (int i = 0, j, k, curr; i < n-1 ;i++) {
        j = i+1, k = n-1;
        while (j < k) {
            curr = a[i].first + a[j].first + a[k].first;
            if (curr == x) {
                cout << a[i].second << " " << a[j].second << " " << a[k].second << "\n";
                return 0;
            }
            else if (curr < x) j++;
            else k--;
        }
    }
    cout << "IMPOSSIBLE" << "\n";
}