#include <bits/stdc++.h>
using namespace std;

vector<int> veca((int)1e5);

int binsearch(int l, int r, int k) {
    int ans = -1, mid;
    while (l <= r) {
        mid = (l+r) / 2;
        if (veca[mid] >= k) {
            ans = veca[mid];
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, q;
    // vector<int> a(n);
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> veca[i];
    for (int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        cout << binsearch(l, r, x) << "\n";
    }
}