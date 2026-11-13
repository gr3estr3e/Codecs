#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, p;
    cin >> n;
    vector<int> presentos(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> p;
        presentos[p] = i;
    }
    cout << presentos[1];
    for (int i = 2; i <= n; i++) cout << " " << presentos[i];
}