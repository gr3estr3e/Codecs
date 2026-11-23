#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int t, coun; cin >> t;
    for (int i = 0, a, b; i < t; i++) {
        coun = 0;
        cin >> a >> b;
        for (int j = a; j <= b; j++) {
            if (j % 10 == j % 7) {
                coun++;
            }
        }
        cout << coun << "\n";
    }
}