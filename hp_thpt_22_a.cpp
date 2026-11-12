#include <bits/stdc++.h>
using namespace std;

int main() {
	string a, b = "virus";
	cin >> a;
	int lena = a.length(), lenb = 5, count = 0;
	for (int i = 0; i <= lena-lenb; i++) {
		int j;
		for (j = 0; j < lenb; j++) {
			if (a[i+j] != b[j]) {
				break;
			}
		}
		if (j == lenb) {
			count++;
		}
	}
	cout << count;
}
