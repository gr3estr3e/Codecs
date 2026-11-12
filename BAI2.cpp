#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("BAI2.INP", "r", stdin);
	freopen("BAI2.OUT", "w", stdout);
	int x, y, dtb;
	cin >> x >> y;
	dtb = (x*3 + y) / 4;
	if (dtb >= 5) {
		cout << 1;
	} else {
		cout << 0;
	}
	
}
