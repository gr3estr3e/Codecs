#include <bits/stdc++.h>
using namespace std;
#define int long long

const int m = 1e6;
vector<bool> sieves(m+1, true);
void sieve() {
    sieves[0] = false;
    sieves[1] = false;
    for (int i = 2; i <= m; i++) {
        if (sieves[i]) {
            for (int j = i*i; j <= m; j+=i) {
                sieves[j] = false;
            }
        }
    }
}

signed main() {
    sieve();
    int ans = 0, ansalt = 0;
    string t, num = ""; cin >> t;
    int n = t.size();
    vector<int> numbers;
    for (int i = 0; i < n; i++) {
        if (isdigit(t[i])) {
            num += t[i];
            ans++;
        } else if (!num.empty()) {
            numbers.push_back(stoll(num));
            num.clear();
        }
    }
    if (!num.empty()) {
        numbers.push_back(stoll(num));
        num.clear();
    }
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] <= m && sieves[numbers[i]]) {
            ansalt = max(ansalt, numbers[i]);
        }
    }
    cout << ans << "\n";
    cout << ansalt << "\n";
}