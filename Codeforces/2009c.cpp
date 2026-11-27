#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x, y, k;
        cin >> x >> y >> k;
        cout << max(2*((x+k-1)/k)-1, 2*((y+k-1)/k)) << endl;
    }
}