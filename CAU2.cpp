#include <bits/stdc++.h>
using namespace std;
#define int long long

const int n = 5e6;
vector<bool> sieves(n+1, true);
void sieve() {
    sieves[0] = false;
    sieves[1] = false;
    for (int i = 2; i <= n; i++) {
        if (sieves[i]) {
            for (int j = i*i; j <= n; j+=i) {
                sieves[j] = false;
            }
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    int ans = 0, ansalt = 0, k = 0;
    string t; cin >> t;
    // int n = t.size();
    // vector<int> numbers;
    // for (int i = 0; i < n; i++) {
    //     if (isdigit(t[i])) {
    //         num += t[i];
    //         ans++;
    //     } else if (!num.empty()) {
    //         numbers.push_back(stoll(num));
    //         num.clear();
    //     }
    // }
    // if (!num.empty()) {
    //     numbers.push_back(stoll(num));
    //     num.clear();
    // }
    // for (int i = 0; i < numbers.size(); i++) {
    //     if (numbers[i] <= 5*m && sieves[numbers[i]]) {
    //         ansalt = max(ansalt, numbers[i]);
    //     }
    // }

    for (int i = 0; i < t.size(); i++) {
        if (t[i] >= '0' && t[i] <='9') {
            ans++;
            k = k * 10 + (t[i] - '0');
            if (k > n) k = n+1;
        } else {
            if (k <= n && sieves[k] == true) {
                ansalt = max(ansalt, k);
            } 
        }
        k = 0;
    }
    
    cout << ans << "\n";
    cout << ansalt << "\n";
}