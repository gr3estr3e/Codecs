#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int n, a;
    cin >> n;
    a = sqrt(n);
    vector<int> divisors;
    for (int i = 1; i*i <= n; i++) {
        for (int j = i; j <= n; j+=i) {
            divisors.push_back(i);
            if (j/i!=i) {
                divisors.push_back(j/i);
            }
        }
    }
    cout << accumulate(divisors.begin(), divisors.end(), 0);
}