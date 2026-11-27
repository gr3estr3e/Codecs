#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, i, j, dp[(int)1e5+1][(int)1e2+1];
vector<int> prefix((int)1e5+1), a((int)1e5+1), b((int)1e2+1);

signed main() {
    // int n, m;
    cin >> n >> m;
    // vector<int> a(n), b(m), prefix;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        prefix[i] = prefix[i-1] + a[i];
    }
    for (int i = 0; i < m; i++) cin >> b[i];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            int s = b[j];
            if (s >= 1 && s < n) {
                s = prefix[i] - prefix[s];
                dp[i][j] = max(dp[i][j], dp[i-s][j-1] + s);
            }
        }
    }
    cout << dp[n][m] << "\n";
    // if (m == 1) s1();
    // else if (m == 2) s2();
    // else s3();

}