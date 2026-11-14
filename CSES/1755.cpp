#include <bits/stdc++.h>
using namespace std;
// #define int long long

signed main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int counter = 0, odds=-1;
    string a, restruct = "";
    cin >> a;
    vector<int> maps(26, 0);
    for (int i = 0; i < a.size(); i++) {
        maps[a[i]-'A']++;
    }
    for (int i = 0; i < 26; i++) {
        if (maps[i] % 2 == 1) {
            counter++;
            odds = i;
        }
    }
    if (counter >= 2) {
        cout << "NO SOLUTION";
        return 0;
    }
    for (int i = 0; i < 26; i++) {
        if (i != odds) {
            for (int j = 0; j < maps[i] / 2; j++) {
                restruct += char(i + 'A');
            }
        }
    }
    if (odds >= 0) {
        for (int i = 0; i < maps[odds]; i++) {
            restruct += char(odds + 'A');
        }
    }
    for (int i = 25; i >= 0; i--) {
        if (i != odds) {
            for (int j = 0; j < maps[i] / 2; j++) {
                restruct += char(i + 'A');
            }
        }
    }
    cout << restruct;
}