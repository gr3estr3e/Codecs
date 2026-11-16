#include <bits/stdc++.h>
using namespace std;

bool differences(int n) {
    int a, b, c, d;
    a = n%10;
    b = (n/10)%10;
    c = (n/100)%10;
    d = (n/1000)%10;
    if (a != b && a != c && b != c && b != d && c != d && d != a) {
        return true;
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    do {
        n++;
    } while (differences(n) != true);
    cout << n << "\n";
}