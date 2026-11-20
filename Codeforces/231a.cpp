#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, coun = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        a = 0;
        for (int j = 0; j < 3; j++) {
            int x, y, z;
            cin >> x >> y >> z;
            a += (x+y+z);
        }
        if (a > 1) coun++;
    }
    cout << coun << "\n";
}