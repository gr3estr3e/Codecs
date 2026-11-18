#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, odd_sum;
    cin >> t;
    for (int i = 1, a, b; i <= t; i++) {
        cin >> a;
        cin >> b;
        odd_sum = 0;
        for (int j = a; j <= b; j++) {
            if (j%2!=0) {
                odd_sum += j;
            }
        }
        cout << "Case " << i << ": " << odd_sum << "\n";
    }
}