#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n, ans = 1, count = 1;;
    string s;
    cin >> s;
    n = s.size();
    for (int i = 1; i < n; i++) { 
        if (s[i] == s[i-1]) {
            count++;
        } else {
            count = 1;
        }
        ans = max(count, ans);
    }
    cout << ans;

}