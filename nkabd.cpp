#include <bits/stdc++.h>
using namespace std;

const int n = 1e5;
vector<int> divs(n+1, 0);

int main() {
    int l, r;
    cin >> l >> r;
    for (int d = 1; d <= n; d++) {
        for (int m = 2*d; m <= n; m+=d) {
            divs[m] += d;
        }
    }
    vector<int> prefix(n+1, 0);
    for (int i = 1; i <= n; i++) {
        if (divs[i] > i) {
            prefix[i] = prefix[i-1] + 1;
        } else {
            prefix[i] = prefix[i-1];
        }
    }
    cout << prefix[r] - prefix[l-1] << "\n";
}