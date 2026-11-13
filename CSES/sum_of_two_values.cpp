#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        if (m.count(x-b)) {
            cout << i + 1 << " " << m[x - b] + 1 << endl;
            return 0;
        }
        m[b] = i;
    }
    cout << "IMPOSSIBLE" << "\n";

}