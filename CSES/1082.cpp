#include <bits/stdc++.h>

#define int long long
using namespace std;
const int mod = 1e9+7, maxn = 1e12;

int sum_divs(int n) {
    vector<int> sums(maxn+1, 0);
    for (int j = 1; j <= n; j++) {
        for (int k = j; k <= n; k+=j) {
            sums[k] += j;
        }
    }
    return sums[n];
}

signed main() {
    int n, ans = 0;
    cin >> n;
    vector<int> sum(maxn+1, 0);
    for (int i = 1; i <= n; i++) {
        sum[i] = sum_divs(i);
    }
    for (int i = 1; i <= n; i++) ans += sum[i];
    cout << ans % mod << "\n";
}