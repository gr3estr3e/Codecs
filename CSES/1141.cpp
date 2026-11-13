#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, l=0, r=0, max_length = 0; cin >> n;
    vector<int> ids(n);
    set<int> indexes;
    for (int i = 0; i < n; i++) cin >> ids[i];

    while (r < n) {
        while (indexes.count(ids[r])) {
            indexes.erase(ids[l]);
            l++;
        }
        indexes.insert(ids[r]);
        max_length = max(max_length, r-l+1);
        r++;
    }
    cout << max_length;
}