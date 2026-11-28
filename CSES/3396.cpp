#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e6;

vector<int> primes;

signed main() {
	vector<bool> marks(maxn+1, true);
	int t; cin >> t;
	marks[0] = false; marks[1] = false;
	for (int i = 2; i <= maxn; i++) {
		if (marks[i]) {
			primes.push_back(i);
			for (int j = i*i; j <= maxn; j+=i) {
				marks[j] = false;
			}
		}
	}
	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		for (int a = n+1; ; a++) {
			if ()
		}
	}
}