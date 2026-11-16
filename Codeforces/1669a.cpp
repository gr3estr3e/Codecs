#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int a; cin >> a;
        if (a >= 1900) {
            cout << "Division 1" << "\n";
        } else if (a >= 1600 and a <= 1899) {
            cout << "Division 2" << "\n";
        } else if (a >= 1400 and a <= 1599) {
            cout << "Division 3" << "\n";
        } else {
            cout << "Division 4" << "\n";
        }
    }
}