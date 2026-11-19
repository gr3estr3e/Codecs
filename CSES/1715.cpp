#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn = 1e6;

signed main() {
    int n, final_prod = 0;
    string a; cin >> a;
    vector<int> counters(n, 0);
    n = a.size();
    for (int i = 1; i < n; i++) {
        if (a[i] == a[i-1]) counters[i]++;
    }
    
}