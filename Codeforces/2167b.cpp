#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a;
        string randomed, purfect;
        cin >> a;
        cin >> randomed >> purfect;
        sort(purfect.begin(), purfect.end());
        sort(randomed.begin(), randomed.end());
        if (randomed == purfect) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
  return 0;
}