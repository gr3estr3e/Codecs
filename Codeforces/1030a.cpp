#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        s += j;
    }
    if (s > 0) {
        cout << "HARD" << "\n";
    } else {
        cout << "EASY" << "\n";
    }
}