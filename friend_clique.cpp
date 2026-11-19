#include <bits/stdc++.h>
using namespace std;
#define int long long

int N, n, m;
vector<int> dsu(50001, -1);

int find(int x) {
    if (dsu[x] < 0) return x;
    int y = find(dsu[x]);
    dsu[x] = y;
    return y;
}

void uni(int x, int y) {
    x = find(x); y = find(y);
    if (x==y) return;
    if (dsu[x] < dsu[y]) {
        dsu[x] += dsu[y];
        dsu[y] = x;
    } else {
        dsu[y] += dsu[x];
        dsu[x] = y;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    while (N--) {
        bool p = true;
        cin >> n >> m;
        for (int i = 0; i < n; i++) dsu[i] = -1;
        vector<int> owes(n);
        vector<int> f_sum(n, 0);
        for (int i = 0; i < n; i++) cin >> owes[i];
        for (int i = 0, x, y; i < m; i++) {
            cin >> x >> y;
            uni(x, y);
        }
        for (int i = 0; i < n; i++) {
            f_sum[find(i)] += owes[i];
        }
        for (int i = 0; i < n; i++) {
            if (f_sum[find(i)] != 0) {
                p = false;
                break;
            }
        }
        cout << (p ? "POSSIBLE\n" : "IMPOSSIBLE\n");
    }
}