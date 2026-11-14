#include <bits/stdc++.h>
using namespace std;

bool greed_check(const vector<long long> &arr, const long long k, long long max_sum) {
    long long subarr = 0, cur_sum = 0;
    for (const long long &x : arr) {
        if (x > max_sum) {
            return false;
        }
        if (cur_sum + x > max_sum) {
            subarr++;
            cur_sum = 0;
        }
        cur_sum += x;
    }
    if (cur_sum > 0) {
        subarr++;
    }
 
    return subarr <= k;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    long long n, k, left = 0, righ = 0;
    cin >> n >> k;
    vector<long long> bruh(n);
    for (long long i = 0; i < n; i++) {
        cin >> bruh[i];
        left = max(left, bruh[i]);
        righ += bruh[i];
    }
 
    while (left < righ) {
        long long mid = (left + righ) / 2;
        if (greed_check(bruh, k, mid)) {
            righ = mid;
        } else {
            left = mid + 1;
        }
    }
    cout << left << "\n";
}