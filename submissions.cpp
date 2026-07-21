#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, count = 0;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (a[i] > 2*a[j]) {
				count++;
			}
		}
	}
	cout << count << "\n";
	return 0;
}