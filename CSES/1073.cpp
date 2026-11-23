#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int n;
    cin >> n;
    multiset<int> cubes;
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        auto it = cubes.upper_bound(a);
        if (it != cubes.end()) {
            cubes.erase(it);
            cubes.insert(a);
        } else {
            cubes.insert(a);
        }
    }
    cout << cubes.size() << "\n";
}