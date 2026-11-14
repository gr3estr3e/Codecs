#include <bits/stdc++.h>
using namespace std;

int sum_digits(int n) {
    int a, b;
    a = n % 10;
    b = n / 10;
    return a+b;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cout << sum_digits(a) << "\n";  
    }
}