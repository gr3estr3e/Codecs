#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("BAI4.INP", "r", stdin);
	freopen("BAI4.OUT", "w", stdout);
	int n, count = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int count_d = 0;
		for (int j = 1; j < i; j++) {
			if (i % j == 0) {
				count_d++;
			}
		}
		if (count_d == 3) {
			count++;
		}
	}
	cout << count;
}
