#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int x, n;
    cin >> x >> n;
    set<int> street;
    multiset<int> distances;
    street = {0,x};
    distances = {x};
    for (int i = 0, a, d; i < n; i++) {
        cin >> a;
        street.insert(a);
        d = *street.upper_bound(a) - *--street.lower_bound(a);
        distances.erase(distances.find(d));
        distances.insert(*street.upper_bound(a) - a); 
        distances.insert(a-*--street.lower_bound(a));
        cout << *--distances.end() << " ";
    }

}