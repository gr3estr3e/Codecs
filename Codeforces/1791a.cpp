#include <bits/stdc++.h>
using namespace std;

int main() {
    string codeforces = "codeforces";
    int t; cin >> t;
    while (t--) {
        string a; cin >> a;
        if (codeforces.find(a) != string::npos) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
}