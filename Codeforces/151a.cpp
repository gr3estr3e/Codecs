#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, l, c, d, p, nl, np, res;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    res = min({((k*l) / nl) , (c*d) , (p/np)});
    cout << res / n << "\n";
}