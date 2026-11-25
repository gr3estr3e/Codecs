#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, i = 0, j = 0, kount = 0, vale;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    while (i < n && j < n) {
        if (a[i] < b[j]) {
            i++;
        } else if (a[i] > b[j]) {
            j++;
        } else {
            vale = a[i];
            kount++;
            i++;
            j++;
            while (i < n && a[i] == vale) i++;
            while (j < n && b[j] == vale) j++;
        }
    }
    cout << kount << "\n";
}