#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n,  ans = 0, curr = 0;
    cin >> n;
    vector<pair<int, int>> tasks(n);
    for (int i = 0; i < n; i++) cin >> tasks[i].first >> tasks[i].second;
    sort(tasks.begin(), tasks.end());
    for (int i = 0; i < n; i++) {
        ans += tasks[i].second - (tasks[i].first + curr);
        curr += tasks[i].first;
    }
    cout << ans << "\n";
}