#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, niggers = 0, countier = 0;
vector<int> dsu(50007, -1);

int find(int x) {
    if (dsu[x] < 0) return x;
    int y = find(dsu[x]);
    dsu[x] = y;
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
    while (true) {
        countier++;
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        for (int i = 1; i <= n; i++) dsu[i] = -1;
        for (int i = 1; i <= m; i++) {
            int a, b;
            cin >> a >> b;
            uni(a, b);
        }
        for (int i = 1; i <= n; i++) {
            if (dsu[i] < 0) {
                niggers++;
            }
        }
        cout << "Case " << countier << ": " << niggers << endl;
    }
}