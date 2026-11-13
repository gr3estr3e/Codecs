#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, k, o;
    cin >> n >> k;
    o = (n+1)/2;
    if (k <= o) {
        cout << 2*k - 1;
    } else {
        cout << 2*(k-o);
    }
}