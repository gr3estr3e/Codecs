#include <bits/stdc++.h>
using namespace std;
#define int long long

int t, f, id;
vector<int> dsu(200007, -1);

int find(int x) {
    if (dsu[x] < 0) return x;
    int y = find(dsu[x]);
    dsu[x] = y;
    return y;
}

int uni(int x, int y) {
    x=find(x);
    y=find(y);
    if (x==y) return abs(dsu[x]);
    if (dsu[x] < dsu[y]) {
        dsu[x]+=dsu[y];
        dsu[y]=x;
        return abs(dsu[x]);
    } else {
        dsu[y]+=dsu[x];
        dsu[x]=y;
        return abs(dsu[y]); 
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> f;
        map<string, int> friend_ind;
        id = 0;
        for (int i = 0; i < f*2; i++) dsu[i] = -1;
        for (int i = 0; i < f; i++) {
            string a, b;
            cin >> a >> b;
            if (friend_ind.find(a) == friend_ind.end()) friend_ind[a] = id++;
            if (friend_ind.find(b) == friend_ind.end()) friend_ind[b] = id++;
            cout << uni(friend_ind[a], friend_ind[b]) << "\n";
        }
    }
}