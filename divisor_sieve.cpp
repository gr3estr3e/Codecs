#include <bits/stdc++.h>
using namespace std;

#define int long long

const int n = 1e6+1;
int divs[n];

void divisor_sieve() {
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j+=i) {
            divs[j] += 1;
        }
    }
}

signed main() {
    divisor_sieve();
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cout << divs[a] << "\n";
    }
}