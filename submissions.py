import sys

sys.setrecursionlimit(400000)

mod = 1000000007

def binary_exp_mod(a, n): # use with m primes only!
    if n == 0: # Degenerate case:
        return 1
    res = binary_exp_mod(a, n//2)
    if n % 2 == 1:
        return ((res * res) % mod * (a % mod)) % mod
    return (res * res) % mod

def factorial(n, cache):
    if n <= 1:
        cache[n] = 1
        return cache[n]
    if cache[n] != 0:
        return cache[n]
    cache[n] = n*factorial(n-1, cache) % mod
    return cache[n]

n = int(sys.stdin.readline())
coffs = []
max_n = 0
for _ in range(n):
    coff_pair = sys.stdin.readline().split()
    coffs.append((int(coff_pair[0]), int(coff_pair[1])))
    max_n = max((int(coff_pair[0]), int(coff_pair[1]), max_n))
factorials = [0] * (max_n+1)
factorial(max_n, factorials)
for pair in coffs:
    n_v = pair[0]
    k_v = pair[1]
    top = factorials[n_v]
    bot = (factorials[k_v] * factorials[n_v - k_v]) % mod
    inv_bot = binary_exp_mod(bot, mod-2)
    ans = (top * inv_bot) % mod
    print(ans)
    