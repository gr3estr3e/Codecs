def reverse_digits(n):
    reversed = 0
    while n > 0:
        reversed = reversed * 10 + n % 10
        n //= 10
    return reversed

def gcd_(a, b):
    if b == 0: return a;
    return gcd_(b, a%b)

a, b = list(map(int, input().split()))
counter = 0
for i in range(a, b+1):
    if gcd_(i, reverse_digits(i)) == 1: counter+=1

print(counter)