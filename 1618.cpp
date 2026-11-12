#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n, zeroes = 0;
    cin >> n;
    while (n >= 5) {
        n /= 5;
        zeroes += n;
    }
    cout << zeroes;
}