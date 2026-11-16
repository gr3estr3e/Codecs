#include <bits/stdc++.h>
using namespace std;

int main() {
    string a;
    cin >> a;
    if (!isupper(a[0])) {
        a[0] = (char)toupper(a[0]);
    }
    cout << a;
}