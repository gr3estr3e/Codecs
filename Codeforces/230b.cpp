#include <bits/stdc++.h>
using namespace std;

#define int long long

const int maxn = 1e6;

signed main() {
    int n, sqrtn; cin >> n;
    vector<int> a(n);
    vector<bool> marks(maxn+1, true);
    marks[0] = false; marks[1] = false;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 2; i <= maxn; i++) {
        if (marks[i]) {
            // primes.push_back(i);
            for (int j = i*i; j <= maxn; j+=i) {
                marks[j] = false;
            }
        }
    }
    for (auto& i : a) {
        int sqrti = sqrt(i);
        if (sqrti * sqrti == i && marks[sqrti] != false) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}