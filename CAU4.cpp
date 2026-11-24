#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, i, j;
vector<int> prefix((int)1e5+1), a((int)1e5+1), b((int)1e2+1);

void s1() {
    int ans = 0, len = b[0];
    for (int i = len; i < n; i++) {
        ans = max(ans, prefix[i] - prefix[i-len]);
    }
    cout << ans << "\n";
}

void s2() {
    int l = b[0], r = b[1], ans = 0;
    vector<int> left((int)1e6), right((int)1e6);
    for (int i = l; i < n; i++) {
        int s = prefix[i] - prefix[i-l];
        left[i] = max(left[i-1], s);
    }
    for (int i = n-r; i >= 0; i--) {
        int s = prefix[i+r] - prefix[i-1];
        right[i] = max(right[i+1], s);
    }
    for (int i = 0; i < n; i++) {
        ans = max(ans, left[i]+right[i+1]);
    }
    cout << ans << "\n";
}

void s3() {
    int dp[(int)1e5+1][(int)1e2+1];
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
}

signed main() {
    // int n, m;
    cin >> n >> m;
    // vector<int> a(n), b(m), prefix;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        prefix[i] = prefix[i-1] + a[i];
    }
    for (int i = 0; i < m; i++) cin >> b[i];
    s3();
    // if (m == 1) s1();
    // else if (m == 2) s2();
    // else s3();

}