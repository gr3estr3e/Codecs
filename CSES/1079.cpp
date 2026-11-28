#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
 
long long binary_exp_modable(long long a, long long n) {
	if (n == 0) {
		return 1;
	}
	long long res = binary_exp_modable(a, n/2);
	if (n%2) {
		return ((res * res) % mod * (a % mod)) % mod;
	}
	else {
		return (res * res) % mod;
	}
}
 
long long factorial_memo(long long n, vector<long long>& cache) {
	if (n <= 1) {
		cache[n] = 1;
		return cache[n];
	}
	if (cache[n] != 0) {
		return cache[n];
	}
	cache[n] = n*factorial_memo(n-1, cache) % mod;
	return cache[n];
}
 
int main() {
	long long n;
	int max_v = 0;
	vector<pair<int, int>> coffs;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		coffs.push_back({a, b});
		max_v = max({max_v, a, b});
	}
	vector<long long> factorials(max_v+1, 0);
	factorials[0] = 1;
  if (max_v >= 1) {
    factorials[1] = 1;
  }
	factorial_memo(max_v, factorials);
	for (const auto& pair : coffs) {
		int n_v = pair.first, k_v = pair.second;
		long long top = factorials[n_v], bot = (factorials[k_v] * factorials[n_v - k_v]) % mod;
		long long inv_bot = binary_exp_modable(bot, mod-2);
		long long ans = (top * inv_bot) % mod;
		cout << ans << "\n";
	}
	return 0;
}