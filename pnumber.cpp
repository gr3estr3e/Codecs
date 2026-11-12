#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, n;
    cin >> a >> b;
    n = sqrt(b);
    vector<bool> marks(n+1, true);
    vector<int> primes;
    marks[0] = false; marks[1] = false;
    for (int i = 2; i <= n; i++) {
        if (marks[i]) {
            primes.push_back(i);
            for (int j = i*i; j <= n; j+=i) {
                marks[j] = false;
            }
        }
    }

    vector<bool> primed(b-a+1, true);

    for (int x = a; x <= min(b, 1); x++) {
       primed[x-a] = false;
    }

    for (int i : primes) {
        for (int j = max(i, (a + i - 1)/i)*i; j <= b; j+=i) {
            primed[j-a] = false;
        }
    }

    for (int i = 0; i <= b-a; i++) {
        if (primed[i]) {
            cout << a+i << "\n";
        }
    }


}