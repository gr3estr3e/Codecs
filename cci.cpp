#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    long long n, x, m = 1e9+7;
    cin >> n >> x;
    vector<int> c(n);
    vector<int> dp(x+1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if(i - c[j] >= 0) {
                (dp[i] += dp[i-c[j]]) %= m;
            }
        }
    }

    cout << dp[x] << "\n";
}