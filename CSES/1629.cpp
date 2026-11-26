#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, times = 0, movies = 0;
    cin >> n;
    vector<pair<int, int>> ins(n);
    for (int i = 0; i < n; i++) cin >> ins[i].second >> ins[i].first;

    sort(ins.begin(), ins.end());
    for (int i = 0; i < n; i++) {
        if (ins[i].second >= times) {
            times = ins[i].first;
            movies++;
        }
    }
    cout << movies << "\n";
}