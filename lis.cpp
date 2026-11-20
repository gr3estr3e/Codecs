#include <bits/stdc++.h>

using namespace std;

int lis(vector<int>& a) {
	int n = a.size();
	vector<int> d(n, 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && j < i) {
				d[i] = max(d[i], d[j] + 1);
			}
		}
	}

	int ans = d[0];
	for (int i=0;i<n;i++) {
		ans = max(ans, d[i]);
	}
	return ans;
}

int main() {
    int n; cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    cout << lis(x) << "\n";
}