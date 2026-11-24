#include <bits/stdc++.h>
using namespace std;
#define int long long

int counter(int n) {
    int period = n/70, reminder = n % 70, res;
    res = period * 7 + min(reminder, (int)6);
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, period; cin >> t;
    // for (int i = 0, a, b; i < t; i++) {
    //     coun = 0;
    //     cin >> a >> b;
    //     for (int j = a; j <= b; j++) {
    //         if (j % 10 == j % 7) {
    //             coun++;
    //         }
    //     }
    //     cout << coun << "\n";
    // }
    for (int i = 0, l, r; i < t; i++) {
        cin >> l >> r;
        cout << counter(r) - counter(l-1) << "\n";
    }
}