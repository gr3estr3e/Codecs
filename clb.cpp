#include <bits/stdc++.h>
using namespace std;

#define int long long

int sum_of_digits(int n) {
	if (n >= 100) return 0;
	int sum_digits = 0;
	while (n >= 0) {
		int a = n % 10;
		sum_digits += a;
		n/=10;
	}
	return sum_digits;
}

int strip_num(int n) {
	if (n >= 999 or n < 0) return 0;
	int singl = n % 10, doubl = (n/10) % 10, tripl = n/100;
	int sum_d = singl + doubl + tripl;
	return sum_d;
}

int f(int x, int y) {
	if (x > y) return x * x;
	else if (x == y) return x + y;
	else return y * y;
}

int factorial(int n) {
	if (n == 0) return 1;
	return n * factorial(n-1);
}

int power_a(int a, int n) {
	int prod = 1;
	for (int i = 1; i <= n; i++) {
		prod *= a;
	}
	return prod;
}

signed main() {
	int a, b;
	cin >> a >> b;
	cout << power_a(a, b);
}