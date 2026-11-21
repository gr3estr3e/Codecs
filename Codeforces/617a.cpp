#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, coun = 0;
    cin >> n;
    if (n % 5 != 0) cout << (n/5)+1 << "\n";
    else cout << n/5 << "\n";
}