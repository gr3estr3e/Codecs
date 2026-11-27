#include <bits/stdc++.h>
using namespace std;
#define int long long   

signed main() {
    int n, x, l, r, i, j;
    cin >> n >> x;
    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i+1;

    sort(a.begin(), a.end());
    for (int i = 0, curr; i < n; i++) {
        for (int j = i+1, k, t; j < n; j++) {
            k = j+1, t = n-1;
            while (k < t) {
                curr = a[i].first + a[j].first + a[k].first + a[t].first;
                if (curr < x) {
                    k++;
                } else if (curr > x) {
                    t--;
                } else {
                    cout << a[i].second << " " << a[j].second << " " << a[k].second << " " << a[t].second;
                    return 0;
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << "\n";

}