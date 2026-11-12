#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int x, y, z;
        cin >> y >> x;
        z = max(y, x);
        if (z % 2 == 1) {
            if (y == z) {
                cout << (z-1)*(z-1) + x << "\n";
            } else if (x == z) {
                cout << z*z - y + 1 << "\n";
            }
        }
        if (z % 2 == 0) {
            if (y == z) {
                cout << z*z - x + 1 << "\n";
            } else if (x == z) {
                cout << (z-1)*(z-1) + y << "\n";
            }
        }
    }
}