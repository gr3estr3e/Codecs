#include <bits/stdc++.h>
using namespace std;
#define int long long
const int n = 1e6;
const int mod = 1e9 + 7;
vector<int> cache(n+1, -1);

int bin_exp(int a, int n, int mod) {
    if (n == 0) return 1;
    if (n == 1) return a % mod;
    int ans = bin_exp(a, n/2, mod);
    if (n % 2) {
        return ((ans * ans) % mod * (a% mod)) % mod;
    } else {
        return (ans * ans) % mod;
    }
}

int factorial(int n) {
    if (n <= 1) {
        cache[n] = 1;
        return cache[n];
    }
    if (cache[n] != -1) {
        return cache[n] % mod;
    }
    cache[n] = n*factorial(n-1) % mod;
    return cache[n];
}

signed main() {
    cache[0] = 1;
    factorial(n);
    int ans = 1;
    vector<int> freq(26, 0);
    string a;
    cin >> a;
    for (auto c : a) {
        freq[c-'a']++;
    }
    for (int i = 0; i < 26; i++) {
        ans = (ans * cache[freq[i]]) % mod;
    }
    cout << (cache[a.size()] * bin_exp(ans, mod - 2, mod)) % mod << "\n";
}