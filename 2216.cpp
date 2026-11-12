#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, count = 1;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, int> index;
    for (int i = 0; i < n; i++) index[a[i]] = i;
    for (int i = 2; i <= n; i++) {
        if (index[i] < index[i-1]) {
            count++;
        }
    }
    cout << count;
}