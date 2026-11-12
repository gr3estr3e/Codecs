#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1), b(m+1);
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[n][m] <<  "\n";

    vector<int> rebuild_lcs;
    while (dp[n][m] > 0) {
        if (a[n] == b[m]) {
            rebuild_lcs.push_back(a[n]);
            n--;
            m--;
        } else if (dp[n-1][m] == dp[n][m]) {
            n--;
        } else {
            m--;
        }
    }
    reverse(rebuild_lcs.begin(), rebuild_lcs.end());
    for (auto i : rebuild_lcs) cout << i << " ";
    return 0;
}