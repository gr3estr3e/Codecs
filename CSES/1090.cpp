#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, left, right, counter = 0;
    cin >> n >> x;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p.begin(), p.end());
    left = 0; right = n-1;
    while (left <= right) {
        if (p[left] + p[right] <= x) {
            counter++;
            left++;
            right--;
        } else if (p[left] + p[right] > x) {
            counter++;
            right--;
        }
    }
    cout << counter;
}