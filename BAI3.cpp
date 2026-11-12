#include <bits/stdc++.h>
using namespace std;

int gcd_e(int a, int b) {
	if (a == 0) {
		return b;
	}
	return gcd_e(b%a, a);
}

int divisor_sieve(	)

int main() {
	freopen("BAI3.INP", "r", stdin);
	freopen("BAI3.OUT", "w", stdout);
	int n, final_gcd = 0, i = 0; j = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	cout << final_gcd;
}
