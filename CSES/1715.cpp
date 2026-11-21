#include <bits/stdc++.h>
using namespace std;
#define int long long
const int n = 1e6;
const int mod = 1e9 + 7;
vector<int> cache(n+1, -1);

int factorial(int n) {
    if (n <= 1) {
        cache[n] = 1;
        return cache[n];
    }
    if (cache[n] != -1) {
        return cache[n] % mod;
    }
    cache[n] = n*factorial(n-1) % mod;
    return cache[n] % mod;
}

signed main() {
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
    cout << (cache[a.size()] / ans) % mod << "\n";
}