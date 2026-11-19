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

#define int long long

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

int factorial(int n, vector<int>& cache) {
	if (n <= 1) {
		cache[n] = n;
		return cache[n];
	}
	if (cache[n] != -1) {
		return cache[n];
	}
	cache[n] = n*factorial(n-1);
	return cache[n];
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

// Greedy algo #1:
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

void res_cus() {
	int n;
 
	cin >> n;
 
	vector<pair<int, int>> times;
 
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		times.push_back({start, 1});
		times.push_back({end, -1});
	}
 
	sort(times.begin(), times.end());
	int curr_ppl = 0;
	int max_ppl = 0;
	for (const pair<int, int> &t : times) {
		curr_ppl += t.second;
		max_ppl = max(max_ppl, curr_ppl);
	}
	cout << max_ppl << "\n";
}

void weird_conjecture(int n) {
	while (n != 1) {
		if (n % 2 == 0) {
			n = n / 2;
			cout << n << " ";
		} else {
			n = 3 * n + 1;
			cout << n << " ";
		}
	}
}

int distinct_nums(vector<int>& a) {
	int count = 1, n = a.size();
	for (int i = 1; i < n; i++) {
		if (a[i] != a[i-1]) {
			count++;
		}
	}
	return count;
}

int distinct_nums_set(vector<int>& a) {
	int count = 1, n = a.size();
	set<int> b;
	for (int i = 1; i < n; i++) {
		b.insert(a[i]);
	}
	return b.size();
}

void traffik_lights() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x, n, tmp, max_range = 0;
    cin >> x >> n;
    set<pair<int, int>> routes = {{0, x}};
    multiset<int> routes_len = {x};
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        auto pos = routes.upper_bound({tmp, 0});
        pos--;
        int start = pos->first, end = pos->second;
        routes.erase(pos);
        routes_len.erase(routes_len.find(end-start));

        routes.insert({start, tmp});
        routes.insert({tmp, end});
        routes_len.insert(tmp-start);
        routes_len.insert(end-tmp);
        cout << *--routes_len.end() << " ";
    }
}

// int maxprod(vector<int> nums&) {
// 	int max_i = max_j = INT_MIN;
// 	int min_i = min_i = INT_MAX;

// }

int music_box(vector<int> &ids) {
	int i = 0, j_max = 0, i_max = 0, n = ids.size();
	map<int, int> mapped;
	for (int j = 0; j < n; j++) {
		if (mapped.find(ids[j]) != mapped.end()) {
			i = max(i, mapped[ids[j]] + 1);	
		}
		mapped[ids[j]] = j;
		if (j - i > j_max - i_max) {
			i_max = i;
			j_max = j;
		}
	}
	return j_max-i_max+1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}	
	cout << music_box(a) << "\n";
	// sort(a.begin(), a.end());
	// cout << distinct_nums(a) << "\n";
	// weird_conjecture(n);

	    // int n, t, lower = 0, upper = 1e9, mid, res;
    // cin >> n >> t;
    // vector<int> efficiency(n);
    // for (int i=0; i < n; i++) {
    //     cin >> efficiency[i];
    // }
 
    // while (lower <= upper) {
    //     int mid = floor((lower + upper) / 2);
    //     int ans = 0;
    //     for (int i = 0; i < n; i++) {
    //         ans += (mid / efficiency[i]);
    //     }
 
    //     if (ans < t) {
    //         lower = mid + 1;
    //     } else {
    //         res = mid;
    //         upper = mid - 1;
    //     }
    // }
    // cout << res << "\n";


    // int t;
    // cin >> t;
    // for (int i = 0; i < t; i++) {
    //     set<int> uniques;
    //     int n;
    //     cin >> n;
    //     for (int j = 0; j < n; j++) {
    //         int tmp;
    //         cin >> tmp;
    //         uniques.insert(tmp);
    //     }
    //     int len = 0;
        
    // }


    // int t;
    // cin >> t;
    // for (int i = 0; i < t; i++) {
    //     int x, n;
    //     cin >> x >> n;
    //     if (n % 2 == 0) {
    //         cout << 0 << "\n";
    //     } else {
    //         cout << x << "\n";
    //     }
    // }

    // int t;
    // cin >> t;
    // for (int i = 0; i < t; i++) {
    //     int n;
    //     cin >> n;
    //     bool even = false, odd = false;
    //     vector<int> tois(n);
    //     for (int j = 0; j < n; j++) {
    //         cin >> tois[j];
    //         if (tois[j] % 2 == 0) {
    //             even = true;
    //         } else {
    //             odd = true;
    //         }
    //     }
    //     if (even && odd) {
    //         sort(tois.begin(), tois.end());
    //     }
    //     for (int j = 0; j < n; j++) {
    //         cout << tois[j] << " ";
    //     }
    //     cout << "\n";
    // }

    // int t;
    // cin >> t;
    // for (int i = 0; i < t; i++) {
    //     int a;
    //     string randomed, purfect;
    //     cin >> a;
    //     cin >> randomed >> purfect;
    //     sort(purfect.begin(), purfect.end());
    //     sort(randomed.begin(), randomed.end());
    //     if (randomed == purfect) {
    //         cout << "YES" << "\n";
    //     } else {
    //         cout << "NO" << "\n";
    //     }
    // }

    // int a, b, c, d, t;
    // cin >> t;
    // for (int i = 0; i < t; i++) {
    //     cin >> a >> b >> c >> d;
    //     if (a == b and b == c and c == d and d == a) {
    //         cout << "YES" << "\n";
    //     } else {
    //         cout << "NO" << "\n";
    //     }
    // }

    // int a, b, yr = 0;
    // cin >> a >> b;
    // while (a<=b) {
    //     a *= 3;
    //     b *= 2;
    //     yr++;
    // }
    // cout << yr << "\n";
    // string input;
    // cin >> input;
    // if (isupper(input[0])) {
    //     cout << input << "\n";
    // } else {
    //     input[0] = toupper(input[0]);
    //     cout << input << "\n";
    // }

    // int n, m;
    // cin >> n >> m;
    // cout << n * m / 2 << "\n";

    // int t;
    // cin >> t;
    // while (t--) {
    //     int n, m ,x ,y;
    //     cin >> n >> m >> x >> y;
    //     int tmp;
    //     for (int p = 0; p < n; p++) {
    //         cin >> tmp;
    //     }
    //     for (int p = 0; p < m; p++) {
    //         cin >> tmp;
    //     }
    //     cout << n+m << "\n";
    // }

    // int t;
    // cin >> t;
    // while (t--) {
    //     int n, m, a0 = 0, b0 = 0, ans = 0;
    //     cin >> n >> m;
    //     for (int i = 0; i < n; i++) {
    //         int a, b;
    //         cin >> a >> b;  
    //         ans += (a-a0);
    //         ans -= ((a-a0+2) % 2) != ((abs(b-b0+2)) % 2);
    //         a0 = a;
    //         b0 = b;
    //     }
    //     ans += (m-a0);
    //     cout << ans << "\n";
    // }

    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++) {
    //     string n;
    //     cin >> n;
    //     reverse(n.begin(), n.end());
    //     for (int i = 0; i < n.size(); i++) {
    //         if (n[i] == 'p') {
    //             n[i] = 'q';
    //         } else if (n[i] == 'q') {
    //             n[i] = 'p';
    //         }
    //     }
    //     cout << n << "\n";
    // }
    
    // int n;
    // cin >> n;
    // for (int i = 0; i < n; i++) {
    //     int m, a, b, c, total=0, left=0;
    //     cin >> m >> a >> b >> c;
    //     if(m>=a){
    //         total+=a;
    //         left+=(m - a);
    //     }else{
    //         total+=m;
    //     }
    //     if(m>=b){
    //         total+=b;
    //         left+=(m - b);
    //     }else{
    //         total+=m;
    //     }
    //     if(left>=c) total+=c;
    //     else total+=left;
    //     cout << total << "\n";
    // }

    // for (int i = 0; i < n; i++) {
    //     int a;
    //     cin >> a;
    //     cout << a-1 << "\n";
    // }

    // string str1;
    // cin >> str1;
    // set<char> uniques(str1.begin(), str1.end());
    // if (uniques.size() % 2 == 0) {
    //     cout << "CHAT WITH HER!" << "\n";
    // } else {
    //     cout << "IGNORE HIM!" << "\n";
    // }

    // string str1, str2;
    // cin >> str1;
    // cin >> str2;
    // transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    // transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    // if (str1 < str2) {
    //     cout << "-1" << "\n";
    // } else if (str2 < str1) {
    //     cout << "1" << "\n";
    // } else {
    //     cout << "0" << "\n";
    // }

    // long long rows=0, cols= 0, ans;
    // vector<vector<int>> scores(6, vector<int>(6, 0));
    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j < 5; j++) {
    //         cin >> scores[i][j];
    //     }
    // }
    // for (int i = 0; i < 5; i++) {
    //     rows++;
    //     for (int j = 0; j < 5; j++) {
    //         cols++;
    //         if (scores[i][j] == 1) {
    //             ans = abs(rows-3) + abs(cols-3);
    //         }
    //         if (cols == 5) {
    //             cols = 0;
    //         }
    //     }
    // }
    // cout << ans << "\n";
    // for (int i = 0; i < max; i++) {
    //     cin >> scores[i];
    // }
    // minimum = scores[k-1];
    // for (int j = 0; j < max; j++) {
    //     if (scores[j] >= minimum and scores[j] > 0) {
    //         ans++;
    //     }
    // }
    // cout << ans << "\n";
    // for (int i = 0; i < max; i++) {
    //     string tmp;
    //     cin >> tmp;
    //     if (tmp.find("++") != -1) {
    //         ans++;
    //     } else {
    //         ans--;
    //     }
    // }
    // cout << ans << "\n";
    // for (int i = 0; i<max; i++) {
    //     int a, b, c;
    //     cin >> a >> b >> c;
    //     if (a + b + c >= 2) {
    //         ans++;
    //     }
    // }
    // cout << ans << "\n";
    // for (int i = 0; i < a; i++) {
    //     long long tmp;
    //     cin >> tmp;
    //     if (tmp > k) {
    //         ans += 2;
    //     } else {
    //         ans++;
    //     }
    // }
    // cout << ans << "\n";
    // string result_matches;
    // cin >> result_matches;
    // for (int i = 0; i < a; i++) {
    //     if (result_matches[i] == 'A') {
    //         anton++;
    //     } else {
    //         danik++;
    //     }
    // }
    // if (anton > danik) {
    //     cout << "Anton" << "\n";
    // } else if (anton == danik) {
    //     cout << "Friendship" << "\n";
    // } else {
    //     cout << "Danik" << "\n";
    // }
    // for (int i = 0; i < a; i++) {
    //     string tmp;
    //     cin >> tmp;
    //     int tmp_size = tmp.size(), reward = tmp_size-2;
    //     if (tmp_size <= 10) {
    //         cout << tmp << "\n";
    //     } else {
    //         string new_tmp = "";
    //         new_tmp += tmp[0];
    //         new_tmp += to_string(reward);
    //         new_tmp += tmp[tmp_size-1];
    //         cout << new_tmp << "\n";
    //     }
    // }
    // if (a == 2) {
    //     cout << "NO" << "\n";
    //     return 0;
    // }
    // if (a % 2 == 0) {
    //     cout << "YES" << "\n";
    // } else {
    //     cout << "NO" << "\n";
    // }
	
	return 0;
}
