#include <bits/stdc++.h>
using namespace std;
#define int long long

int t, n, coun;
double d, x, y;
vector<int> dsu(1001, -1);

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
        cin >> n >> d;
        for (int i = 0; i < n; i++) dsu[i] = -1;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            if (x - y <= d) {
                uni(x, y);
            }
        }
        coun = 0;
        for (int i = 0; i < n; i++) {
            if (dsu[i] < 0) {
                coun = min(dsu[i], coun);
            }
        }
        cout << "Case " << t << " " << abs(coun) << "\n";
    }
}