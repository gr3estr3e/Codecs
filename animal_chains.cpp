#include <bits/stdc++.h>
using namespace std;
#define int long long

int c, r, coun;
vector<int> dsu(5005, -1);

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
    while (true) {
        cin >> c >> r;
        if (c == 0 && r == 0) return 0;
        for (int i = 0; i < c; i++) dsu[i] = -1;
        map<string, int> animals;
        for (int i = 0; i < c; i++) {
            string a; cin >> a;
            animals[a] = i;
        }
        while (r--) {
            string prey, pred;
            cin >> prey >> pred;
            uni(animals[prey], animals[pred]);
        }
        coun = 0;
        for (int i = 0; i < c; i++) {
            if (dsu[i] < 0) {
                coun = min(dsu[i], coun);
            }
        }
        cout << abs(coun) << "\n";
    }
}