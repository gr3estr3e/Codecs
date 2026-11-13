#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> dp(n,(vector<int>(n, 0)));
    if (a[0][0] == '.') dp[0][0] = 1;
    else dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            if (a[i][j] == '*') {
                dp[i][j] = 0;
            } else {
                if (i > 0) {
                    dp[i][j] = (dp[i-1][j] + dp[i][j]) % (int)(1e9+7);
                } if (j > 0) {
                    dp[i][j] = (dp[i][j] + dp[i][j-1]) % (int)(1e9+7);
                }
            }
        }
    }
    cout << dp[n-1][n-1];
}