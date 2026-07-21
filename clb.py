# import math

# r=float(input("Bán kính:"))
# S=r*r*math.pi
# C=r*2*math.pi
# print("Diện tích:", '{:.5f}'.format(S))
# print("Chu vi:", '{:.5f}'.format(C))

# ax=int(input("Độ dài cạnh huyền 1: "))
# bx=int(input("Độ dài cạnh huyền 2: "))
# cx=(ax**2+bx**2)**0.5
# print('{:.0f}'.format(cx))
# print(int(cx))

# h=float(input())
# x=float(input())
# print((1/2)*x*h)

# a=float(input())
# b=float(input())
# print(a*b)
# print((a+b)*2)

# a=float(input())
# b=float(input())
# def f(x, y):
#     return x**3 + y**3 +x*y
# print(int(f(a, b)))

# G=9.8
# h=float(input())
# v=(2*G*h)**0.5
# print('{:.4f}'.format(v))

# a=float(input())
# b=float(input())
# c=float(input())

# p=(1/2)*(a+b+c)
# S=(p*(p-a)*(p-b)*(p-c))**0.5
# print(S)
# print('{:.3f}'.format(S))

def linear_func(a, b):
    if a == 0:
        print("a = 0. Aborting")
        quit()
    x=(-b/a)**0.5
    return "{:.3f}".format(x), "{:.3f}".format(-x)
# print("PT co 2 nghiem la:", f(float(input()), float(input())))

def sum_of_digits(n):
    if n >= 100:
        return f"{n} > 99"
    sum_digits=0
    while n != 0:
        n_1=n%10
        sum_digits+=n_1
        n//=10
    return sum_digits
# print(sum_of_digits(int(input())))

def strip_num(n):
    if n >= 999 or n < 0:
        return f"{n} not satisfied"
    donvi=n%10
    chuc=(n//10)%10
    tram=n//100
    sumz=donvi+chuc+tram
    return f"Tong cac chu so cua so {n} la:", sumz, tram, chuc, donvi
# print(strip_num(int(input())))
# n=int(input())
# print((n*(n+1))/2)

n = int(input())
if n >= 5:
    print("Di hoc")
else:
    print("Nghi")

# a=int(input())
# b=int(input())
# c=int(input())
# if a > 0 and b > 0 and c > 0:
#     print("a, b, c is all positive")
# else:
#     print("one (or some) is negative, check")

# n=int(input("Candies: "))
# m=int(input("Babies: "))
# if n%m == 0:
#     print("YES")
# else:
#     print("NO")

# a=int(input())
# b=int(input())
# c=int(input())
# if a**2 + b**2 == c**2:
#     print("YES")
# else:
#     print("NO")

def f(x, y):
    if x>y:
        return x**2
    elif x==y:
        return x+y
    else:
        return y**2

def check_greater(a, b, c):
    if c / b == a and b / a == a:
        return "YES"
    else:
        return "NO"
    
# print(check_greater(int(input()), int(input()), int(input())))

def check_number1(m, n, k):
    result_mult=m*n*k
    if len(str(result_mult)) > 2 and result_mult%10 == 0:
        return "YES"
    else:
        return "NO"
# print(check_number1(int(input()), int(input()), int(input())))

def check_triangle_type(a, b, c):
    if a**2 + b**2 == c**2 or a**2 + c**2 == b**2:
        return "Vuông"
    if a == b:
        return "Cân"
    if a == b and b == c:
        return "Đều"
    else:
        return "Thường"
# print(check_triangle_type(int(input()), int(input()), int(input())))

def factorial(n):
    if n == 0:
        return 1
    return n*factorial(n-1)
# print(factorial(int(input())))


def a_power_n(a, n):
    return a ** n