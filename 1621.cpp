#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n;
    cin >> n;
    set<int> uniques;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        uniques.insert(a);
    }
    cout << uniques.size();
}