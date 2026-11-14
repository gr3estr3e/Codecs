#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    bool flag = false;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a != 0) flag = true;
    }
    if (flag != false) cout << "HARD" << "\n";
    else cout << "EASY" << "\n";
}