#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    multiset<int> h;
    for (int i = 0; i < n; i++) {
        int a; cin >> a; h.insert(a);
    }
    for (int i = 0; i < m; i++) {
        int t; cin >> t;
        auto it = h.upper_bound(t);
        if (it==h.begin()) {
            cout << "-1\n";
        } else {
            it--;
            cout << *it << "\n";
            h.erase(it);
        }
    }
}