#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m, coun = 0, countier = 0, t;
vector<int> dsu(500007, -1);

int find(int x) {
    if (dsu[x] < 0) return x;
    int y = find(dsu[x]);
    dsu[x] = y;
    return y;
}

void uni(int x, int y) {
    x=find(x);
    y=find(y);
    if (x==y) return;
    if (dsu[x] < dsu[y]) {
        dsu[x]+=dsu[y];
        dsu[y]=x;
    } else {
        dsu[y]+=dsu[x];
        dsu[x]=y;
    }
}

signed main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) dsu[i] = -1;
        for (int i = 0, a, b; i < m; i++) {
            cin >> a >> b;
            uni(a, b);
        }
        coun = 0;
        for (int i = 1; i <= n; i++) {
            if (dsu[i] < 0) {
                coun = max(abs(dsu[i]), coun);
            }
        }
        cout << coun << "\n";
    }
}