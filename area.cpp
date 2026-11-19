#include <bits/stdc++.h>
using namespace std;

int main() {
    int sum = 0, n;
    cin >> n;
    while (n--) {
        int x, y, x1, y1;
        cin >> x >> y >> x1 >> y1;
        sum += abs(x1-x) * abs(y1-y);
    }
    cout << sum << "\n";
}