#include <bits/stdc++.h>
using namespace std;
#define int long long

int distinct_nums(vector<int>& a) {
	int count = 1, n = a.size();
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i-1]) {
			count++;
		}
	}
	return count;
}

signed main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}	
	sort(a.begin(), a.end());
	cout << distinct_nums(a) << "\n";
	return 0;
}