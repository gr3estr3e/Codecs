#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, ans = "";
    cin >> a;
    ans+=a[0];
    ans+=to_string(a.size()-2);
    ans+=a[a.size()-1];
    cout << ans << "\n";
}