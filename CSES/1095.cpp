#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef unsigned __int128 int128;
const int mod = 1e9+7;

int bin_exp(int a, int n) {
    if (n == 0) return 1;
    if (n == 1) return a % mod;
    int res = bin_exp(a, n/2) % mod;
    if (n % 2) return ((int128)(res * res) * a) % mod;
    else return (int128)(res * res) % mod;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while (n--) {
        int a, b;
        cin >> a >> b;
        cout << bin_exp(a, b) % mod << "\n";
    }
}