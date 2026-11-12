#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, count=0;

    cin >> n;
    string pigga[n];
    for (int i = 0; i < n; i++) {
        cin >> pigga[i];
    }
    for (int i = 0; i < n; i++) {
        if (pigga[i] != pigga[i-1]) {
            count++;
        }
    }
    cout << count << "\n";
}