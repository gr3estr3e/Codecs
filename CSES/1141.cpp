#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l, r, maxl = 0; cin >> n;
    vector<int> k(n); for (int i = 0; i < n; i++) cin >> k[i];
    map<int, int> indexes;

    l = 0, r = 0;
    while (r < n) {
        if (indexes.find(k[r]) != indexes.end()) {
            l = max(l, indexes[k[r]] + 1);
            indexes[k[r]] = r;
            r++;
        } else {
            indexes[k[r]] = r;
            r++;
        }
        maxl = max(maxl, r-l);
    }
    cout << maxl << "\n";
}