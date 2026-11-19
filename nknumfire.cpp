#include <bits/stdc++.h>
using namespace std;

int reverse_digits(int n) {
    int reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

int gcdalt(int a, int b) {
    if (b == 0) return a;
    return gcdalt(b, a % b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, coun=0;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        if (gcdalt(i, reverse_digits(i)) == 1) coun++;
    }
    cout << coun << "\n";
}