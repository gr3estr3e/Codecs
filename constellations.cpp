#include <bits/stdc++.h>
using namespace std;
#define int long long

int t, n, coun;
double d, x, y, euclidean_distance;
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
    for (int c = 1; c <= t; c++) {
        cin >> n >> d;
        vector<pair<double, double>> coords(n);
        for (int i = 0; i < n; i++) dsu[i] = -1;
        for (int i = 0; i < n; i++) {
            cin >> coords[i].first >> coords[i].second;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                euclidean_distance = (coords[i].first - coords[j].first) * (coords[i].first - coords[j].first) + (coords[i].second - coords[j].second) * (coords[i].second - coords[j].second);
                if (euclidean_distance <= d*d + 1e-9) {
                    uni(i, j);
                }
            }
        }
        coun = 0;
        for (int i = 0; i < n; i++) {
            if (dsu[i] < 0) {
                coun++;
            }
        }
        cout << "Case " << c << ": " << coun << "\n";
    }
}