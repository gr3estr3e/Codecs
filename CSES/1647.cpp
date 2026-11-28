#include <bits/stdc++.h>
#define int long long

using namespace std;
const int n = 2e5, k = 30;
int st[k][n];

int preprocessing() {
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < (1 << i) <= n; j++) {
            st[i][j] = min(st[i-1][j], st[i-1][j+(1 << (i-1))]);
        }
    }
}

int 