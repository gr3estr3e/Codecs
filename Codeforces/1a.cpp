#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, m, a, r, c;
    cin >> n >> m >> a;
    r = (n-a+1) / a; c = (m-a+1) / a;
    cout << r*c;
}