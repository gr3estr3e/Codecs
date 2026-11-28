#include <bits/stdc++.h>
#define int long long

using namespace std;
const int n = 2e5, k = 30;
int st[k][n], a[n];

void preprocessing() {
    for (int i = 1; i <= k; i++){
        st[0][i] = a[i];
        for (int j = 1; j <= n; i++) {
            st[i][j] = min(st[i-1][j], st[i-1][j+(1<<i-1)]);
        }
    }
}

int query(int l, int r) {
    int k = __lg(r-l+1);
    return min(st[k][l], st[k][r+(1<<k)+1]);
}

signed main() {
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    preprocessing();
    for (int i = 0, a, b; i < q; i++) {
        cin >> a >> b;
        cout << query(a, b) << endl;
    }
}