#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef __int128_t int128;
signed main() {
    int n, t, l, r, mid, final_ans = -1;
    int128 counter;
    vector<int> k;
    cin >> n >> t;
    for (int i = 0, a; i < n; i++) {
        cin >> a; k.push_back(a);
    }
    l = 0; r = 1e18; 
    while (l <= r) {
        mid = (l+r) / 2;
        counter = 0;
        for (int i = 0; i < n; i++) counter += mid / k[i];
        if (counter < t) {
            l = mid +1;
        } else {
            final_ans = mid;
            r = mid -1;
        }
        // cout << "TEST: " << mid << ": " << (int)counter << endl;
    }
    cout << final_ans << "\n";
}