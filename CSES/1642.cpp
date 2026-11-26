#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, l, r, i, j;
    cin >> n >> x;
    vector<pair<pair<int,int>>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first.first, a[i].second.second = i;

    sort(a.begin(), a.end());

    l = 0, r = 0;
    while (l < r)

}