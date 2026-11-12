#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen("SODEP.INP","r",stdin);
	freopen("SODEP.OUT","w",stdout);
	int n, t = 0;
	cin >> n;
	while (n != 0) {
		t += (n%10);
		n/=10;
	}
	if (t % 10 == 9) {
		cout << 1;
	} else {
		cout << 0;
	}
}
