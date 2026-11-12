#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, max_p = 0, current = 0, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        current = current - a + b;
        max_p = max(max_p, current);
    }
    cout << max_p << "\n";
}