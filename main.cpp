// #include <iostream>
// #include <vector>
// // #include <complex>
// #include <list>
// #include <map>
// #include <string>
// #include <set>
// #include <math.h>
// #include <algorithm>
#include <bits/stdc++.h>

using namespace std;

// All algorithms learned written in C++, for references and learning
// Using as least libraries as possible

// Sieve of Eratosthenes:
int sieve(int n) {
	vector<bool> primes_mark(sqrt(n) + 2, true);
	vector<int> primes;
	primes_mark[0] = primes_mark[1] = false;
	for (int i = 2; i*i <= ceil(sqrt(n)); i++){
		if (primes_mark[i]) {
			primes.push_back(i);
			for (int j = i*i; j <= n; j += i) {
				primes_mark[j] = false;
			}
		}
	}
	return primes_mark[n];
}

// Heron's square root algorithm: ONLY USE FOR POSITIVE REALS, NO NEGATIVES YET: O(1) worst case!
float sqrt_H(int s) { 
	float guess = s * 0.5f;
	for (int i = 0; i < 15; i++) {
		guess = 0.5f * (guess + s/guess);
	}
	return guess;
}

// Fast inverse square root: O(1) worst case!
float sqrt_F(float s) {
	long i;
	float x2, y;
	const float thricehalves = 1.5f;
	x2 = s * 0.5f;
	y = s;
	i = * (long *) &y; // copy the content of memory address of y to i
	i = 0x5f3759df - (i>>1); // shift bit of i to the right by 1 bit -> i = i / 2 and subtract it by approx. sqrt(2^127)
	y = * (float *) &i; // copy the modified content back
	y = y * (thricehalves-(x2*y*y)); // newton method of approximating
	return y;
}

// Binary Search.
int binary_search(int l, int r, vector<int>& a, int k) {
	if (l > r) {
		return -1;
	}
	int mid = l + ((r-l) / 2);
	if (a[mid] < k) {
		return binary_search(mid+1, r, a, k);
	}
	if (a[mid] > k) {
		return binary_search(l, mid-1, a, k);
	}
	return mid;
}

// Linear Search.
int linear_search(int ind, vector<int>& a, int k) { // vector passed with & - pass by reference
	if (ind == a.size()) {
		return -1;
	}
	if (a[ind] == k) {
			return ind;
	}
	return linear_search(ind+1, a, k);
}

vector<int> bubble_sort(vector<int>& a) {
	int n = a.size();
	bool swapped = true;
	while (swapped != false) {
		swapped = false;
		for (int i = 1; i < n; i++) {
			if (a[i-1] > a[i]) {
				swap(a[i], a[i-1]);
				swapped = true;
			}
		}
	}
	return a;
}

// Euclidean Algorithm for finding GCD (Greatest Common Divisor):
int gcd_euclid(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd_euclid(b, a%b);
}

// // Extended Euclidean Algorithm:
// int gcd_euclid_extended(int a, int b, int& x, int& y) {
// 		if (b == 0) {
// 			x=1;
// 			y=0;
// 			return a;
// 	}
// 	int x1, y1;
// 	int d = gcd_euclid_extended(b, a%b, x1, y1);
// 	x=y1;
// 	y=x1-y1*(a/b);
// 	return d;
// }

// Binary Exponentiation:
long long binary_exp(int a, int n) {
	if (n == 0) {
		return 1;
	}
	long long res = binary_exp(a, n/2);
	if (n%2) {
		return res * res * a;
	}
	else {
		return res * res;
	}
}

// Primality check naive way:
bool check_prime(int n) {
	if (n <= 1) {
		return false;
	}
	for (int i = 2; i < n; i++) {
		if (n%i==0) {
			return false;
		}
	}
	return true;
}

// Fibonacci:
long long fib(long long n) {
	long long a=0, b=1, tmp = 0;
	long long mods = binary_exp(10, 9);
	for (long long i=0; i < n; i++) {
		tmp = (a+b) % mods;
		b=a;
		a=tmp;
	}
	return tmp;
}

// Fibonacci with Memoization:
long long fib_memo(long long n, vector<int>& cache) {
	if (n <= 1) {
		cache[n] = n;
		return cache[n];
	}
	if (cache[n] != -1) {
		return cache[n];
	}
	cache[n] = fib_memo(n-1, cache) + fib_memo(n-2, cache);
	return cache[n];
}

// Longest Increasing Subsequence: O(n^2) original idea of the thing:
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

int lis_with_binary(vector<int>& a) {
	int n = a.size(), j;
	const long INF = 1e9;
	vector<int> d(n+1, INF);
	d[0] = -INF;

	for (int i = 0; i < n; i++) {
		j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
		if (d[j-1] < a[i] && a[i] < d[j]) {
			d[j] = a[i];
		}
	}

	int ans = 0;
	for (int i=0;i<=n;i++) {
		if (d[i] < INF) {
			ans = i;
		}
	}
	return ans;
}

// // Bubble Sort.
// vector bubble_sort(vector<int>& a) {
// 	for (int i = 0; i < a.size(); i++) {
// 		if (a[i] > a[i-1]) {
// 			swap(a[i], a[i-1]);
// 		}
// 	}
// 	return a;
// }

vector<int> sqrt_decomposite_preprocessing(vector<int>& a) {
	int n = a.size(), s = ceil(sqrt(n));
	vector<int> b;
		for (int k = 0; k < s; k++) {
		int b_v = 0, start = k*s, end = min(n-1, (k+1) * s-1);
		for (int i = start; i <= end; i++) {
			b_v += a[i];
		}
		b.push_back(b_v);
	}
	return b;
}

int query(int l, int r, int len, vector<int>& a, vector<int>& b) { // len = s
	int sum = 0, c_l = l / len, c_r = r / len;
	if (c_l == c_r) {
		for (int i = l; i <= r; i++) {
			sum += a[i];
		}
	} else {
		for (int i = l; i < (c_l + 1) * len; i++) {
			sum += a[i];
		}
		for (int i = c_l + 1; i < c_r; i++) {
			sum += b[i];
		}
		for (int i = c_r * len; i <= r; i++) {
			sum += a[i];
		}
	}
	return sum;
}

void update(int k, int i, int s, vector<int>& a, vector<int>& blocks) {
	int block = k/s;
	blocks[block] += i-a[k];
	a[k] = i;
}

// CSES task 2216, naive ver.
int collecting_numbers_naiive(int n, vector<int>& sequence) {
	int rounds = 0, count = 1;
	while (count <= n) {
		for (int j = 0; j < n; j++) {
			if (sequence[j] == count) {
				count += 1;
			}
		}
		rounds += 1;
	}
	return rounds;
}

// CSES task 2216
int collecting_numbers(int n, vector<int>& numbers) {
	map<int, int> indexed;
	int rounds = 1;
	for (int i = 0; i < n; i++) {
		indexed[numbers[i]] = i;
	}
	for (int j=2; j <= 2; j++) {
		if (indexed[j] < indexed[j-1]) {
			rounds++;
		}
	}
	return rounds;
}

int min_price(int n, vector<int>& a, vector<int>& b) {
	int min_p = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < b[i]) {
			min_p += a[i];
		} else {
			min_p += b[i];
		}
	}
	return min_p;
}

// Greedy algo #1: associated with tasks 1619 & 1629 on CSES
void movie_restaurant() {
	int n, count = 0, end_time = 0;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		int first, second;
		cin >> first >> second;
		a[i].first = second;
		a[i].second = first;
	}
	sort(a.begin(), a.end());
	for (pair<int, int> &cus_mov : a) {
		if (cus_mov.second >= end_time) {
			count++;
			end_time = cus_mov.second;
		}
	}
	cout << count << "\n";
}

int main() {
	// int n;
	// cin >> n;
	// vector<int> a(n);
	// for (int i = 0; i < n; i++) {
	// 	cin >> a[i];
	// }
	// cout << lis_with_binary(a) << "\n";
	movie_restaurant();
	return 0;
}