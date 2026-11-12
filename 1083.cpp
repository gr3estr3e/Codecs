#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n, sum, sum_pregiven = 0;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a;
        cin >> a;
        sum_pregiven += a;
    }
    sum = (n*(n+1))/2;
    cout << sum - sum_pregiven;
}