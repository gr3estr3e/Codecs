#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, kth_score, counter = 0;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    kth_score = a[k-1];
    for (int i = 0; i < n; i++) {
        if (a[i] >= kth_score && a[i] > 0) counter++;
    }
    cout << counter;
}