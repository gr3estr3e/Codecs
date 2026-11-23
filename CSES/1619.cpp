#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, max_ppl = 0, curr;
    cin >> n;
    vector<pair<int, int>> times;
    for (int i = 0, a, b; i<n;i++) {
        cin >> a >> b;
        times.push_back({a, 1});
        times.push_back({b, -1});
    }
    curr = 0;
    sort(times.begin(), times.end());
    for (int i = 0; i < 2*n; i++) {
        curr += times[i].second;
        max_ppl = max(max_ppl, curr);
    }
    cout << max_ppl << "\n";
}