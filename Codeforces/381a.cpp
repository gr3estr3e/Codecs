#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, r, a1, b1, pick; cin >> n;
    bool turns = true;
    vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];

    l = 0, r = n-1, a1=0, b1=0;
    while (l <= r) {
        if (a[l] >= a[r]) {
            pick = a[l];
            l++;
        } else {
            pick = a[r];
            r--;
        }
        if (turns) {
            a1 += pick;
        } else {
            b1 += pick;
        }
        turns = !turns;
    }
    cout << a1 << " " << b1 << "\n";
}