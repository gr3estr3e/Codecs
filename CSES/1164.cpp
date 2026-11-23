#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n, max_rooms = 0;
    cin >> n;
    vector<tuple<int, int, int>> customers;
    vector<int> free, ans(n);
    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        customers.push_back({a, -1, i});
        customers.push_back({b, 1, i});
    }
    sort(customers.begin(), customers.end());
    for (auto [day, type, id] : customers) {
        if (type == -1) {
            if (free.size() == 0) {
                max_rooms++;
                ans[id] = max_rooms;
            } else {
                ans[id] = free.back();
                free.pop_back();
            }
        }
        if (type == 1) {
            free.push_back(ans[id]);
        }
    }
    cout << max_rooms << "\n";
    for (auto i : ans) cout << i << " ";
    cout << "\n";
}