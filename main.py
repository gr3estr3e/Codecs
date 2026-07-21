# Libraries used:
import math
import sys
# import struct
# import re
# import itertools
# from collections import deque
# from random import randrange
# from random import randint
# # import matplotlib.pyplot as pyplot
# import turtle
# import tkinter
from bisect import *


# Algorithms self-built: these things are SO fucking cool man
# Check if n is prime (schoolbook algorithm)
def check_prime(n):
    if n == 0 or n == 1:
        return False
    for i in range(2, int(n**0.5)):
        if n % i == 0: 
            return False
    return True

# ABSOLUTE VALUE!
def abs_value(n):
    if n < 0:
        return -n
    else:
        return n

# Greatest Common Divisor (GCD) Euclid's Algorithm!
def gcd_homemade(a, b):
    if b == 0:
        return a
    return gcd_homemade(b, a%b)

# Largest Common Multiple (LCM)!
def lcm_homemade(a, b):
    abs_a_b = abs(a*b)
    return abs_a_b // gcd_homemade(a, b)

# BINARY SEARCHHHHHHHHH!!!!
def binary_search(l, r, a, k):
    if l > r:
        return None
    mid = math.floor(l + ((r-l) / 2))
    if a[mid] < k:
        return binary_search(mid+1, r, a, k)
    if a[mid] > k:
        return binary_search(l, mid-1, a, k)
    return mid

# LINEAR SEARCH: requires a iterable, a element in that iterable. For "ind" please input 0.
def linear_search(ind, a, k):
    if ind == len(a):
        return None
    if a[ind] == k:
        return ind
    return linear_search(ind+1, a, k)

# # BUBBLE SORT:
def bubble_sort(a):
    for i in range(len(a)):
        swapped = False
        for j in range(1, len(a)):
            if a[j-1] > a[j]:
                a[j-1], a[j] = a[j], a[j-1]
                swapped = True
        if not swapped:
            break
    return a
# print(bubble_sort(list(map(int, input().split()))))

# Sieve of Eratosthenes: check if n is prime without naive primality checking
def sieve(n):
    primes_mark = [True] * (n+1)
    primes = []
    primes_mark[0] = primes_mark[1] = False
    for i in range(2, n): # Check from 2 -> N because 0 and 1 are not primes already.
        if primes_mark[i] == True and i*i <= n: # Marks the current prime multiples as not prime.
            primes.append(i)
            for j in range(i*i, n+1, i):
                primes_mark[j] = False
    return primes_mark[n]

# a, b = list(map(int, input().split()))
# for i in (a, b):
#     if sieve(i):
#         print(i)

# Square root alogrithm (Heron):
def square_root_H(s): # Returns -1 if n is negative
    if n < 0:
        return -1
    guess = abs_value(s/2)
    for i in range(0, 15):
        guess = 1/2 * (guess + abs(s)/guess) # Applying formula: xn+1 = 1/2 (xn - S/xn)
    return guess
# print(square_root_H(int(input())))

# def insertion_sort(a):
#     n = len(a)
#     for i in range(1, n):
#         next = a[i]
#         j = i-1
#         for j in range(j, 0, -1):
#             a[j+1] = a[j]
#         a[j+1] = next
#     return a
# # print(insertion_sort(list(map(int, input().split()))))

# def linear_sieve(n):
#     lp = [0] * (n+1)
#     pr = []
#     for i in range(2, n):
#         j=0
#         if lp[i] == 0:
#             lp[i] = i
#             pr.append(i)
#             while j <= n:
#                 lp[i*pr[j]] = pr[j]
#                 if pr[j] == lp[i]:
#                     break
#                 j+=1
#     return lp[n]
# print(linear_sieve(100))

# Other codes collected from learning sessions:
# listvalues=[0, 1, 0]
# n=0
# while n < 20:
#     for i in range(n, n+2, 1):
#         if i == 0:
#             listvalues[i] = 0
#         else:
#             value=listvalues[i] + listvalues[i+1]
#             listvalues.append(value)
#         print(listvalues)
#
#     n+=1
#
# D_CONST_SETABLE=int(input("Exponent: "))
# N_SETABLE=int(input("Base: "))
# target=int(input("Targeted number to view: "))
# result=D_CONST_SETABLE*(target-1)+N_SETABLE
# print(result)
# result2=N_SETABLE*(D_CONST_SETABLE**2+target)
# print(result2)
#
# n=int(input("Random integer: "))
# temp=0
# temp2=0
# exponent=9
# count=0
# listoffortunate=[]
# if n > 10**9:
#     exit()
# else:
#     for i in range(0, n):
#         temp += exponent
#         count += 1
#         if count == 10:
#             exponent *= 2
#             count = 0
#         listoffortunate.append(temp)
#         if temp < n:
#             temp2 += temp
#     print("result: " + str(temp2))
#     print(listoffortunate)
#

#Bài 4:
# n=int(input("Random INTEGER: "))
# result=1
# for i in range(1 , n):
#     result *= i
# print(result)
#
# n = int(input("Max :"))
# result = 0
# for i in range(1, n+1):
    # res1 = i**2
    # result += res1
# print(result)

# n = int(input("Max: "))
# res=0
# for i in range(n+1):
    # denom=1/(2*i-1)
    # res+=denom
# print(res)
# n=str(input("Number: "))
# print("Length: " + str(len(n)))
# res1=0
# for i in n:
    # res1+=int(i)
# print("Sum of digits in the number n: " + str(res1))    
# print("Sum of characters of n: " +str(res1))

# res2=0
# for o in range(1, int(n)):
    # if cheque_prime(o) == True:
        # print(o)
        # res2+=o
# print("Sum of primes less than n: " + str(res2))
# listofprimecloseton=[]
# for g in range(2, int(n)):
    # if cheque_prime(g) == True:
        # listofprimecloseton.append(g)
# print(listofprimecloseton)
# print("Nearest prime: "+ str(listofprimecloseton[-1]))
# a=int(input("The \"a\" number: "))
# b=int(input("The \"b\" number: "))
# if a < 10 or b < 10:
    # exit()
# print(math.gcd(a, b))
# print(f"Amount of numbers from {a} to {b}: {(b-a)-1}")
def is_perfect_square(x):
    if x >= 0:
        sr = int(x ** 0.5)
        return (sr * sr == x)
    return False
# greedy=[]
# for i in range(a,b):
#     if is_perfect_square(i) == True:
#         greedy.append(i)
# print(greedy)

def nprogram():
    n=int(input("DeezNutz: "))
    p=0
    nalt=n
    while n != 0:
        lost=n%10
        p+=lost
        n//=10
    print(p)
    s=0
    for i in range(1, nalt+1):
        res1 = (-(math.pow(-1, i))/(i+1))
        s += res1
    print(s)
    k=0
    for g in range(nalt, 1, -1):
        k=g
        # k*(k+1)*(k+2)/3
        t=(k*(k+1)*(k+2))/3
        if t < nalt**2:
            print(k)
            break

def onsitting():
    s=input("String: ")
    a=''
    for num in s:
        # print(num)
        if num.isdigit() == True:
            a += num
    print(a)
    within=''
    for bs in a:
        if bs.isdigit() == True:
            within += bs
            for g in within:
                if within[-1] in ['0', '5']:
                    print(within)
                    break
        else:
            print("KHONG MAN")
    t=0
    temp=re.findall(r'\d+', s)
    for finale in temp:
        t += int(finale)
    # print(temp)
    print(t)

def robberyplanbl():  
    n=int(input("cockerman: "))
    houses = []
    goldscollected = 0
    for i in range(1, n+1):
        houses.append(int(input(f"Golds in house {i}: ")))
    for golds in range(0, len(houses), 2):
        goldscollected += houses[golds]
    print(goldscollected)
# robberyplanbl()


def combina(n, k, m):
    lsited = []
    res2 = []
    for i in range(1, n+1):
        lsited.append(i)
    comresults = list(itertools.combinations(lsited, k))
    for nigge in comresults:
        if sum(nigge) % 3 == 0:
            res2.append(nigge)
            # print(sum(nigge))
            # print(nigge)
    # print(res2)
    print(len(res2))

   
# combina(a, b, c)

def combina2(n, k, S):
    alists = []
    for i in range(1, n+1):
        inpot = int(input('Number: '))
        alists.append(inpot)
    print(alists)
    listed = list(itertools.combinations(alists, k))
    listed2 = []
    for o in listed:
        if sum(o) <= 10:
            listed2.append(o)
            print(o)
    print(listed)
    print(listed2)

# combina2(a, b, c)

def permu(n):
    res1 = list(itertools.permutations(range(1, n+1)))
    res2 = []
    def check_for_firsttwo(tup):
        tup2 = list(tup)
        statemented = []
        for i in range(0, len(tup2)-1):
            for nobbles in range(0, len(tup2)):
                if tup[i+1] - tup[i] != 1:
                    statemented.append(True)
                else:
                    statemented.append(False)
            print(statemented)
            if all(gelement == True for gelement in statemented) == True:
                res2.append(tup)
            statemented.clear()
    def check_list_for_trues(listed):
        return all(listed)
    for i in res1:
        check_for_firsttwo(i)
    print(res2)

# a = int(input("n number: "))
# b = int(input("m(ax) number: "))
# c = int(input("k number: "))
# permu(a)

def listed2():
    a = [1, 3, 2, 5, 6]
    max = None
    for i in range(0, len(a)):
        if a[i] < a[i+1]:
            max = i
    print(max)

def listeddeeznutz():
    n = int(input("How many elements: "))
    n2 = int(input("Karget_number: "))
    nlist = []
    for i in range(1, n+1):
        nlist.append(int(input(f"Number {i}: ")))
    # print(n)
    max1 = 0
    max2 = 0
    for p in nlist:
        if p > max1:
            max2 = max1
            max1 = p
    nlist.remove(max1)
    print('largest sum: ' + format(max1 + max2))
    def check_diff(listed, n):
        min1 = 10**5
        for i in range(len(listed)-1):
            sum1 = listed[i] + listed[i+1]
            if abs(sum1 - n) < min1:
                min1 = abs(sum1 - n)
                a1 = listed[i]
                a2 = listed[i+1]
        return min1, a1, a2
    print(check_diff(nlist, n2))
    
def minimumwage():
    listed = []
    for i in range(1, int(input("max: "))+1):
        listed.append(int(input(f"Number {i}: ")))
    print(listed)
    min3 = itertools.combinations(listed, r=3)
    minimumvalue = 10 ** 5
    value = 0
    for i in list(min3):
        for g in i:
            value += g
        print(value)
        if value < minimumvalue:
            minimumvalue = value
    print("minimum value: " + str(minimumvalue))

def arraya():
    listed = []
    for i in range(1, int(input("max: "))+1):
        listed.append(int(input(f"Number {i}: ")))
    print(listed)
    min3 = itertools.combinations(listed, r=3)
    maxvalue = 0
    value = 0
    for i in list(min3):
        for g in i:
            value += g
        print(value)
        if value > maxvalue and value % 5 == 0:
            maxvalue = value
    print("max value: " + str(maxvalue))

def wbackpack():
    w = int(input("max weight: "))
    itemsbackpack = []
    for g in range(1, int(input("Max items: "))+1):
        itemsbackpack.append(((int(input("Value: ")), int(input("Weight: ")))))
    print(itemsbackpack)
    maxvalue = 0
    itemsallowed = []
    combinationsofitems = itertools.combinations(itemsbackpack, r=2)

def LIS(a):
    n = len(a)
    d = [1] * n
    for i in range(n):
        for j in range(i):
            if a[j] < a[i]:
                d[i] = max(d[i], d[j]+1)
    ans = d[0]
    for i in range(n):
        ans = max(ans, d[i])
    return ans
# n = int(input())
# print(LIS(list(map(int, input().split()))))

def LIS_with_binary(a, n):
    INF = float('inf')
    d = [INF] * (n+1)
    d[0] = -INF
    for i in range(n):
        j = bisect_left(d, a[i])
        if d[j-1] < a[i] and a[i] < d[j]:
            d[j] = a[i]

    ans = 0
    for i in range(n+1):
        if d[i] < INF:
            ans = i
    return ans

# n = int(input())
# sequence_root = list(map(int, input().split()))
# print(LIS_with_binary(sequence_root, n))

def chessboard():
    n = int(input("Column: "))
    m = int(input("Row: "))    
    board = [[1, 2, 3, 4], [5, 6, 7, 8]]
    startingpoint = board[0][0]
    dest = board[n][m]
    print(dest, startingpoint)
# chessboard()

def work1(n, a, b):
    a = [0] + a
    b = [0] + b
    dp = [0] * (n+1)
    dp[1] = a[1]
    for i in range(2, n+1):
        dp[i] = min(dp[i - 1] + a[i], dp[i - 2] + b[i - 1])
    print(dp[n])

def fib(n):
    if n <= 1:
        return n
    return fib(n-1) + fib(n-2)

# for i in range(0, 20):    
#     print(fib(i))

def perfect_number(n):
    sumz = 1
    if n <= 0:
        return False
    for i in range(2, n):
        if n % i == 0:
            sumz += i
    return sumz==n
# print(perfect_number(int(input("Number: "))))

def largest_and_smallest_numbers(n):
    the_nmb_dissolved_max = []
    the_nmb_dissolved_for_min = []
    if len(n) > 10:
        return str(n) + "Length exceeded."
    elif int(n) == 0:
        return n + "the number is 0."
    else:
        for i in n:
            the_nmb_dissolved_max.append(int(i))
            the_nmb_dissolved_for_min.append(int(i))
        # print(the_nmb_dissolved)
        max_value = 5
        # min_value = 0
        result_num_max=[]
        result_num_min=[]
        for digits in range(len(the_nmb_dissolved_max)):
            max_value=max(the_nmb_dissolved_max)
            result_num_max.append(max_value)
            the_nmb_dissolved_max.remove(max_value)
            print(result_num_max, the_nmb_dissolved_max)
        # if the_nmb_dissolved_for_min[-1] == 0:
        #     the_nmb_dissolved_for_min.remove(the_nmb_dissolved_for_min[-1])
        # for digits2 in range(len(the_nmb_dissolved_for_min)):
        #     result_num_min.append(result_num_max[-1])
        #     print(result_num_min)

def sieve_with_length(n):
    is_prime = [True] * (n+1)
    for p in range(2, int(math.sqrt(n))+1):
        if is_prime[p]:
            for i in range(p**2,n+1,p):
                is_prime[i]=False
    prime=[i for i, prime in enumerate(is_prime) if prime]
    return len(prime), prime

# totale=0
# for i in a:
#     for num in i:
#         totale+=num
# print(totale)

# print(sum(a))

# a=[]
# for i in range (0,5):
#     row=list(map(int, input().split()))
#     a.append(row)
# # print(a)
# # Đường chéo chính: 1,1 (0,0) -> 3,3 (2,2)
# sum_green=0
# for i in range(len(a)):
    # for j in range(len(a)):
    #     if j == i:
    #         # print(a[i][j])
    #         sum_green+=a[i][j]
# print(sum_green)

# # Đường chéo phụ: 3,1 (2,0) -> 1,3 (0,2)
# sum_red=0
# for i in range(len(a)):
    # for j in range(len(a)):
    #     # print(a[i][j])
    #     if j+i == len(a)-1:
    #         sum_red+=a[i][j]
# print(sum_red)


def fib(n):
    if n <= 1:
        return n
    return fib(n-1) + fib(n-2)


sys.setrecursionlimit(100000)
# Fibonacci with Memoization DP:
def fib_memo(n, cache):
    if n <= 1:
        cache[n] = n
        return cache[n]
    if cache[n] != -1:
        return cache[n]
    cache[n] = fib_memo(n-1, cache) + fib_memo(n-2, cache)
    return cache[n]

# n = int(input())
# memo_n = [-1] * (n+1) 
# print(fib_memo(n, memo_n))

# fib_seq=[]
# for i in range(0, 20):
#     fib_seq.append(fib(i))

# mata=[[10,2,22],
#       [987,167,613],
#       [1597,89,4181]]

def colve(mat, m, n, i, j):
    if i < 0 or i >= m or j < 0 or j <= n or mat[i][j] == 0:
        return 0
    right=colve(mat, m, n, i, j + 1)
    bottom=colve(mat, m, n, i + 1, j)
    bottom_right=colve(mat, m, n, i + 1, j + 1)
    return 1+min(right, bottom, bottom_right)
def csqm(mat, m, n):
    ans=0
    for i in range(m):
        for j in range(n):
            if mat[i][j] == 1:
                ans+=colve(mat, m, n, i, j)
    return ans

def sort_row(row_sort):
    for i in range(len(row_sort),2):
        for j in range(1, i-1):
            if row_sort[j] > row_sort[j+1]:
                row_sort[j], row_sort[j+1] = row_sort[j+1], row_sort[j]
    return row_sort

# 31/12/2025:
"""Một dãy số được tạo thành theo quy luật đặc biệt như sau:
Số thứ nhất là 2


Số thứ hai là 5


Từ số thứ ba trở đi:
 a[i] = a[i-1] * 2 - a[i-2] + i


Yêu cầu:
 Viết chương trình nhập vào số nguyên n (1 ≤ n ≤ 30), in ra số thứ n trong dãy.
Ví dụ:
Input: 5  
Output: 36"""
# n = int(input("n="))
# a=[2, 5]
# if n == 1:
#     print(a[0])
# elif n == 2:
#     print(a[1])
# else:
#     for i in range(3, n):
#         a.append(a[i-1] * 2 - a[i-2] + i)
#     print(a)

# 31/12/2025 #2:
""" Cho một ma trận vuông n x n (n ≤ 20), gồm các số nguyên dương.
Yêu cầu:
Viết chương trình xoay 180 độ ma trận


Sau đó tính tổng các số chia hết cho 3 ở các đường chéo chính và phụ


Ví dụ:
yaml
Sao chépChỉnh sửa
Input:  
3  
1 2 3  
4 5 6  
7 8 9  

Sau khi xoay 180 độ:
9 8 7  
6 5 4"""
# n = int(input("n lines = "))
# n_mat = []
# for i in range(n):
#     row = list(map(int, input().split()))
#     n_mat.append(row)
# print(n_mat)

# # PASCAL TRIANGLE TEMPLATE
# def bin_coef(n, k):
#     res = 1
#     if k > n-k:
#         k=n-k
#     for i in range(k):
#         res *= (n-i)
#         res //= (i+1)
#     return res

# def pas_tri(n):
#     if n >= 60:
#         return
#     mat = []
#     for row in range(n):
#         arr = []
#         for i in range(row+1):
#             arr.append(bin_coef(row, i))
#         mat.append(arr)
#     return mat

# pascal_triangel=pas_tri(int(input()))
# for i in pascal_triangel:
#     print(i)

# # Permutations and Combinations using Python's 'itertools' library:
# print(list(itertools.combinations(range(int(input())+1), int(input()))))
# print(list(itertools.permutations(range(int(input())+1), int(input()))))

# Permutations and Combinations MANUALLY:
# # Formulas implementation:

def factorial(n):
    if n == 0:
        return 1
    elif n == 1:
        return n
    else:
        return n*factorial(n-1)

# def combinations_formulas(n, k):
#     return factorial(n) // (factorial(k) * factorial(n-k))
# print(combinations_formulas(4, 2))
# def permutations_formulas(n, k):
#     return factorial(n) // factorial(n-k)
# print(permutations_formulas(4, 2))

# # Printing pairs implementation:
# def nxt_comb(a, n, k):
#     i = k-1
#     while i >= 0 and a[i] == n-k+i+1:
#         i-=1
#     if i <0:
#         return False
#     a[i] += 1
#     for j in range(i+1, k):
#         a[j] = a[j-1] +1
#     return True
# numbers=list(range(0, 10))
# n, k = map(int, input().split())
# a = [i+1 for i in range(k)]
# while True:

# # exponents w/ negative powers:
# def negative_exponents(a_original, n_egative):
#     def exponents(a, n):
#         if n == 0:
#             return 1
#         return a*exponents(a, n-1)
#     if n_egative < 0:
#         return 1/exponents(a_original, abs(n_egative))
# print(negative_exponents(120, -2)) # TEST

# s=input()
# if s[len(s)-3:len(s)] == '.py':
#     print("YES")
# else:
#     print("NO")

# s=input()
# count_a_appearances=0
# for i in range(len(s)):
#     if s[i] == 'a':
#         print(i, end=' ')
#         count_a_appearances+=1
# print('\n', count_a_appearances)

# s=input()
# s_splitted=s.split()
# print(len(s_splitted))
# for i in s_splitted:
#     print(i)

# ho_va_ten=input()
# print(ho_va_ten.upper())

# s=input()
# s_plit=s.split()
# for i in s_plit:
#     print(i, end=' ')

# x=input()
# y=input()
# if sorted(x) == sorted(y):
#     print("YES")
# else:
#     print("N0")

# sintr_=input()

# sintr_lenth=len(sintr_)
# sintr_numbers=''
# sintr_lowercases=''
# sintr_uppercases=''
# for i in range(sintr_lenth):
#     if sintr_[i].isnumeric() == True:
#         sintr_numbers+=sintr_[i]
#     elif sintr_[i].isupper() == True:
#         sintr_uppercases+=sintr_[i]
#     else:
#         sintr_lowercases+=sintr_[i]
# sintr_arranged=sintr_numbers+sintr_uppercases+sintr_lowercases
# print(sintr_arranged)


# # Fibonacci sequence by recursion: O{2^n) -> extremely inefficient
# def fibonacci(n):
#     if n <= 1:
#         return n
#     return fibonacci(n-1) + fibonacci(n-2)
# for i in range(int(input("n = "))):
#     print(f"The value of the {i} Fibonacci number is {fibonacci(i)}")

# Fibonacci sequence by list (procedure): 
# n=int(input("n = "))


# # Fibonacci sequence by list, done right (with counter):
# n = int(input('n='))
# fib_seq_proc=[0, 1]
# for i in range(2, n+1):
#     fib_num_i=fib_seq_proc[i-1]+fib_seq_proc[i-2]
#     fib_seq_proc.append(fib_num_i)
#     print(f"The {i}th Fibonacci number is:", fib_num_i)
# print(f"Whole Fibonacci set of {n} numbers:", fib_seq_proc)
# # print(len(fib_seq_proc))

# # Harmonic Series:
# harmonic_sum=0
# n=1
# while True:
#     harmonic_sum+=(1/n)
#     print(f"n = {n}", f"Harmonic sum: {harmonic_sum}")
#     n+=1


# # Half of Harmonic Series:
# harmonic_sum_half=0
# n=2
# while True:
#     harmonic_sum_half+=(1/n)
#     print(f"n = {n}", f"Half Harmonic sum: {harmonic_sum_half}")
#     n+=2

# # Collatz Conjecture:
# n=int(input())
# f_n_collatz=[n]
# while n != 1:
#     if n % 2 == 0:
#         n//=2
#         f_n_collatz.append(n)
#     else:
#         n=3*n+1
#         f_n_collatz.append(n)
# print(f_n_collatz)

# Integer sequences BY LIST:

# # Lucas sequence by list:
# luc_seq_proc=[2, 1]
# n=int(input("n = "))
# for i in range(2, n+1):
#     luc_seq_i=luc_seq_proc[i-1]+luc_seq_proc[i-2]
#     print(f"The {i}th Lucas sequence number is:", luc_seq_i)
#     luc_seq_proc.append(luc_seq_i)
# print(luc_seq_proc)

# # Tribonacci sequence by list:
# tri_seq_proc=[0, 1, 1]
# n=int(input('n = '))
# for i in range(3, n+1):
#     tri_seq_i=tri_seq_proc[i-1]+tri_seq_proc[i-2]+tri_seq_proc[i-3]
#     tri_seq_proc.append(tri_seq_i)
# print(tri_seq_proc)

# # Power of 2 (i^2) sequence by list:
# pow_2_seq_proc=[]
# n = int(input())
# for i in range(1, n+1):
#     pow_2_seq_proc.append(2**i)
# print(pow_2_seq_proc)

# # DSAs:
# # 1st: Stack - Kiểu dữ liệu ngăn xếp
# def Stack():
#     return []
# def push(S, element):
#     return S.append(element)
# def pop(S):
#     value = S[-1]
#     return S.pop(value)
# def isEmpty(S):
#     if not S:
#         return True
#     return False
# def top(S):
#     return S[-1]
# Stock = Stack()

# push(Stock, 2)
# push(Stock, 3)
# push(Stock, 5)
# print(Stock)
# print(top(Stock))

# # Câu 1:
# x, y = list(map(int, input().split()))
# a, b, c, d = list(map(int, input().split()))
# # print(x+y)
# sum_x_y = x+y
# if sum_x_y == a:
#     print("A")
# elif sum_x_y == b:
#     print("B")
# elif sum_x_y == c:
#     print("C")
# elif sum_x_y == d:
#     print("D")
# else:
#     print("No")


# # Câu 2:
# N, K, T = list(map(int, input().split()))
# a = list(map(int, input().split()))
# counter_freeship = 0
# # print(N_Z)
# for i in a:
#     if i % T == 0 and i > K:
#         print(i, end=' ')
#         counter_freeship += 1
# print(counter_freeship)

# # Câu 3:
# T, S = list(map(int, input().split()))
# stringed_T = str(T)
# stringed_S = str(S)
# counter_match = 0
# for i in stringed_S:
#     for j in stringed_T:
#         if i == j:
#             counter_match+=1
# # print(f"{counter_match} matches")
# if counter_match == 6:
#     print(2000)
# elif counter_match == 5:
#     print(50)
# else:
#     print(0)

# # Exponential function:
# n=int(input())
# x=int(input())
# euler=0
# for i in range(n):
#     euler += math.pow(x, i)/math.factorial(i)
# print(euler)


# Matrices:
# n, m, p = list(map(int, input().split()))
# mata = []
# matb = []
# veca = []

# for i in range(n):
#     row_i = []
#     for j in range(m):
#         row_i.append(j)
#     mata.append(row_i)
#     matb.append(row_i)
# for i in range(m):
#     veca.append(i)

# for i in range(m, 0, -1):
#     row_i = []
#     for j in range(p, 0, -1):
#         row_i.append(j)
#     # vec_n_row.append(i)
#     matb.append(row_i)

# Matrix x Matrix multiplication (let A[n][m] and B[m][p]:
"""
Input: matrices A and B
Let C be a new matrix of the appropriate size
For i from 1 to n:
    For j from 1 to p:
        Let sum = 0
        For k from 1 to m:
            Set sum ← sum + Aik × Bkj
        Set Cij ← sum
Return C
O(n^3) run time
"""

def mat_mat_mulp(mata, matb, n, m, p):
    matc=[]
    for i in range(n):
        row_i = []
        for j in range(p):
            sum_row = 0
            for k in range(m):
                sum_row += mata[i][k] * matb[k][j]
            row_i.append(sum_row)
        matc.append(row_i)
    return matc

# # Matrix x Vector multiplication:
# """
# Let matrix A size n x m, vector B length m (since B is just a matrix with size m x 1):
# For i from 1 to n:
#     Let sum = 0
#     For j from 1 to m:
#         Set sum <- sum + A[i][j] * B[j]
#     Set (vec) Cj = sum
# Return C
# """

def mat_vec_mulp(veca, mata, n, m):
    vecc=[]
    for i in range(n):
        sum_row = 0
        for j in range(m):
            sum_row += mata[i][j] * veca[j]
        vecc.append(sum_row)
    return vecc

# Matrix addition:
def mat_mat_add(mata, matb, n, m):
    matc=[]
    for i in range(n):
        row_c=[]
        for j in range(m):
            row_c.append(mata[i][j] + matb[i][j])
        matc.append(row_c)
    return matc

# print(mata)
# print(matb)
# print(veca)

# print(mat_mat_mulp(mata, matb, n, m, p))
# print(mat_vec_mulp(veca, mata, n, m))
# print(mat_mat_add(mata, matb, n, m))

# Anonymous function:
# notlamb = lambda x: 2*x+2
# print(notlamb(20))

# Nearly practical use of lambda function
# number = [3, 6, 9, 12, 15]
# tripled = list(map(lambda x: x*3, number))
# print(tripled)

# x = int(input())

def recursion(n):
    if n == 0 or n >= 1000:
        return 0
    return 6*n+3*recursion(n-1)

# print(recursion(x))

# for i in range(x):
#     print(f"At x = {i}, the recursive function returns {recursion(i)}")

# syntax:  λvaribles.body (lambda variables: expression)
# how_to_lambda = lambda x, y, z: 3*x + 4*y - 5*z
# print(how_to_lambda(3, 2, 4))

# randomized_numbers=[]
# for i in range(1, 9):
#     randomized_numbers.append(randint(1, i))
# print(randomized_numbers)

# a = int(input())
# b = int(input())
# x1=[]
# y1=[]
# x2=[]
# y2=[]
# for i in range(-3, 3):
#     x1.append(i)
#     y1.append(a*i+b)
# for i in range(-3, 3):
#     x2.append(i)
#     y2.append(-a*i+b)

# for i in range(a+1):
#     x1.append(i)
#     y1.append(fib(i))

# pyplot.xlabel("x")
# pyplot.ylabel("y")

# pyplot.grid(axis='x')
# pyplot.grid(axis='y')
# pyplot.grid(linewidth=0.5)

# pyplot.scatter(x1, y1, label = f"y = x!")
# # pyplot.plot(x2, y2, label = f"y = -{a}x+{b}")
# pyplot.show()

# draw_slave = Turtle()
# draw_slave.pencolor("green")
# draw_slave.pensize(2)

# n=int(input())
# size = n

# while n > 0:
#     for i in range(3):
#         draw_slave.fd(size)
#         draw_slave.lt(120)
#     n -= 10
#     size *= 0.8

# mainloop

def factorial(n):
    if n == 1:
        return n
    return n*factorial(n-1)
# print(factorial(int(input("n = "))))

def fibonacci(n):
    a = 0
    b = 1
    for i in range(2, n):
        tmp = a+b
        a = b
        b = tmp
    return a
# for i in range(int(input("n = "))+1):
#     print(fibonacci(i))

# n = int(input())
# print(fibonacci(n) / fibonacci(n-1))

def fibonacci_procedure(n):
  fib_n_seq = [0, 1]
  golden_ratio=0

  for i in range(2, n+1):
    fib_n_seq.append(fib_n_seq[i-1]+fib_n_seq[i-2])
    # print(f"The {i}th Fibonacci number is {fib_n_seq[i]}") # Test prints
  return fib_n_seq[n]
    # # print(fib_n_seq) # Test prints
    # golden_ratio = fib_n_seq[i] / fib_n_seq[i-1] # Test prints
    # print(f"At {i}th decimal precision, the golden ratio is {golden_ratio}") # Test prints

def lucas(n):
    if n == 0:
        return 2
    if n == 1:
        return n
    return lucas(n-1)+lucas(n-2)
# print(lucas(20))

def fib_closed_form(n):
    return round(((1+square_root_H(5)/2)**n)/square_root_H(5))
# print(fib_closed_form(16))

# # Assuming that two matrices ARE EQUAL SQUARE MATRICES.
# def check_two_matrices_equality(mata, matb):
#     flag = 0
#     for i in range(len(mata)):
#         for j in range(len(mata)):
#             if mata[i][j] == matb[i][j]:
#                 flag = 1
#     if flag == 1:
#         return True
#     else:
#         return False

# mat1 = []
# for i in range(2):
#

def prime_factorization(a):
    P = []
    F = []
    for i in range(2, a):
        if check_prime(i) == True:
            P.append(i)
    for p in P:
        if a % p == 0:
            F.append(p)
            a//=p
    return P, F
# print(prime_factorization(150))

# rad = int(input())
# drawer = turtle.Turtle()
# for i in range(2):
#     turtle.circle(rad, 90)
#     turtle.circle(rad // 2, 90)
# tkinter.mainloop()

# # B4 2*
# n_umbers=[]
# n=int(input())
# for i in range(n):
#     n_umbers.append(int(input()))
# res = n_umbers[0] + n_umbers[1]
#     # Consider every pair, find its sum and
#     # update result if we get a smaller value
# for i in range(n - 1):
#     for j in range(i + 1, n):
#         sum = n_umbers[i] + n_umbers[j]
#         if abs(sum) < abs(res):
#             res = sum
#         elif abs(sum) == abs(res):
#             res = max(res, sum)
# print(res)

# last = {}
# l = 0
# ans = 0
# for r, ch in enumerate(s):
#     if ch in last and last[ch] >= l:
#         l = last[ch] + 1
#     last[ch] = r
#     ans += r - l + 1

# print(ans,last,l)

# import itertools

# n=int(input())
# range_n=list(range(1, n+1))
# perms = list(itertools.combinations(range_n, r=2))
# satisfaction = 0
# for i in perms:
#     print(i)
#     sum_tup = 1
#     for j in i:
#         # print(j)
#         sum_tup *= j
#     print(sum_tup)
#     if sum_tup % 2 == 0:
#         satisfaction += 1
#     else:
#         continue
# print(satisfaction)

# def tRy(i, n, x):
#     if i == n:
#         print(''.join(map(str, x)))
#         return
#     for v in [0, 1]:
#         x[i] = v
#         tRy(i+1, n, x)
# n=int(input())
# x=[0]*n
# tRy(0, n, x)

# # Cách 2: mảng & quy tắc "tăng nhị phân"
# def nxt_bin(x):
#     i = len(x) -1
#     while i >= 0 and x[i] == 1:
#         x[i] == 0
#         i-=1
#     if i <0:
#         return False
#     x[i] = 1
#     return True

# n=int(input())
# x=[0]*n
# while True:
#     print(''.join(map(str, x)))
#     if not nxt_bin(x):
#         break

# import itertools

# # B5 2* !WORKING NOW!
# ca_n_dies = int(input())
# k_ids = int(input())
# candies_template = list(itertools.permutations(range(ca_n_dies), k_ids))
# candies_good = []
# for i in candies_template:
#     if min(i) != 0 and sum(i) <= ca_n_dies:
#         candies_good.append(i)
# for j in candies_good:
#     print(j, end=' ')
# print(len(candies_good))

# # Nay ôn mấy bài cơ bản (7/1/2026)
# """ 1. Đếm số chẵn trong dãy
# Yêu cầu:
#  Nhập số n, sau đó nhập n số nguyên.
#  Đếm xem có bao nhiêu số chẵn.

# 2. Tìm số lớn thứ hai
# Yêu cầu:
#  Nhập n số nguyên (n ≥ 2).
#  Tìm số lớn thứ hai (không trùng số lớn nhất).

# 3. Kiểm tra số nguyên tố
# Yêu cầu:
#  Nhập số nguyên dương n.    
#  In "YES" nếu n là số nguyên tố, ngược lại in "NO".

# 4. Đếm chữ số lớn nhất
# Yêu cầu:
#  Nhập số nguyên dương n.
#  Đếm xem chữ số lớn nhất xuất hiện bao nhiêu lần.

# 5. Tách số chẵn – lẻ
# Yêu cầu:
#  Nhập n số nguyên.
#  In ra: 
# Dòng 1: các số chẵn

# Dòng 2: các số lẻ
#  (mỗi số cách nhau một dấu cách)

# 6. Số đảo ngược
# Yêu cầu:
#  Nhập số nguyên dương n.
#  In ra số đảo ngược của n.
# Ví dụ:
# Input: 12034
# Output: 43021

# 7. Chuỗi đối xứng
# Yêu cầu:
#  Nhập một chuỗi.
#  Kiểm tra xem chuỗi có đối xứng hay không.

# 8. Đếm từ trong chuỗi
# Yêu cầu:
#  Nhập một dòng văn bản.
#  Đếm số từ (các từ cách nhau bởi khoảng trắng).

# 9. Tìm phần tử xuất hiện nhiều nhất
# Yêu cầu:
#  Nhập n số nguyên.
#  Tìm số xuất hiện nhiều lần nhất (nếu hòa, lấy số nhỏ hơn).

# 10. Tính tổng các số nguyên tố ≤ n
# Yêu cầu:
#  Nhập số nguyên dương n.
#  Tính tổng các số nguyên tố nhỏ hơn hoặc bằng n."""

# # B1:
# n = int(input())
# list_n=[]
# even_counter=0
# for i in range(n):
#     list_n.append(int(input()))
# for j in list_n:
#     if j % 2:
#         print(j)
#         even_counter+=1
# print(even_counter)

# # B2:
# n=int(input())
# list_n_find=[]
# for i in range(n):
#     list_n_find.append(int(input()))
# list_n_find.remove(max(list_n_find))
# print(max(list_n_find))

# # B3:
# n_2 = int(input())
# if check_prime(n_2) == True:
#     print("YES")
# else:
#     print("NO")

# # B4:
# n = int(input())
# n_factored = []
# for i in str(n): n_factored.append(int(i))
# max_val_in_factor = max(n_factored)
# counter = 0
# for j in n_factored:
#     if j == max_val_in_factor:
#         counter+=1
# print(max_val_in_factor)
# print(counter)

# # B5:
# n = int(input())
# list_n_numbers=[]
# list_n_even=[]
# list_n_odd=[]
# for i in range(n):
#     list_n_numbers.append(int(input()))
# for j in list_n_numbers:
#     if j % 2 == 0:
#         list_n_even.append(j)
#     else:
#         list_n_odd.append(j)
# for h in list_n_even:
#     print(h, end=' ')
# print('\n')
# for g in list_n_odd:
#     print(g, end=' ')

# # B6
# n=int(input())
# print(str(n)[::-1])

# # B7
# n=input()
# n_length=len(n)
# n_first_halves=n[:n_length//2]
# n_second_halves=n[n_length//2:]
# if n_second_halves[::-1] == n_first_halves:
#     print("YES")
# else:
#     print("MO")

# # B8
# string_input=input().split()
# words_dict=list(map(str, input().split()))
# counter=0
# for i in string_input:
#     print(i)
#     if i in words_dict:
#         counter = 1
# print(counter)

# # B10
# n = int(input())
# sumz=0
# for i in range(n+1):
#     if check_prime(i) == True:
#         sumz+=i
# print(i)

# n = input()
# count_correct = 0
# list_wait = list(map(int, input().split()))

# for i in range(len(list_wait)):
#     if list_wait[i] == i+1:
#         count_correct+=1
# print(count_correct)


# n, m, k = list(map(int, input().split()))
# # print(n, m, k)
# cost = float('inf')
# for x in range(1, 201):
#     if x < k:
#         total = x
#     else:
#         total = x + x//5

#     if total >= n:
#         cost = min(cost, x*m)
# print(cost)

# n = int(input())
# kmin = math.ceil(math.sqrt(10**(n-1)))
# kmax = math.floor(math.sqrt(10**n)-1)
# def sum_xsquares(n):
#     return n*(n+1)*(2*n+1)//6
# # print(kmin, kmax)
# print(sum_xsquares(kmax) - sum_xsquares(kmin-1))

# n, k = list(map(int, input().split()))
# # print(list(itertools.permutations(range(1, k+1), n)))
# dp = [0] * (n+1)
# dp[0] = 1
# for i in range(1, n+1):
#     for j in range(1, k+1):
#         if i - j >= 0:
#             dp[i] += dp[i-j] # CT truy hồi
# print(dp[n])

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
    sum_digits = 0
    while n != 0:
        n_1=n%10
        sum_digits+=n_1
        n//=10
    return sum_digits
# print(sum_of_digits(int(input())))

def missing_c(values):
    a, b, x = list(map(int, values.split()))
    return 3 * x - a - b
# print(missing_c(input()))

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

# n = int(input())
# if n >= 5:
#     print("Di hoc")
# else:
#     print("Nghi")

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

#Kieerm tra
# # B6:
# PI=3.14
# r=int(input())
# print("Dien tich hinh tron:", "{:.2f}".format(r**2*PI))
# print("Chu vi hinh tron:", "{:.2f}".format(r*2*PI))

# # B7:
# a=int(input())
# b=int(input())
# c=int(input())
# if a == b and b == c:
#     print("La tam giac deu")
# else:
#     print("Khong la tam giac deu")

# # B8:
# a_1, b_1, c_1=list(map(float, input().split()))
# avg=(a_1+b_1+c_1)//3
# if avg > 5.0:
#     print("Qua mon")
# else:
#     print("Khong qua mon")

# # 7b, 7c:
# a, b, c=list(map(int, input().split()))
# if a == b or b == c or c == a:
#     print("La tam giac can")
# else:
#     print("Dell la tam giac can")

# if a**2 + b**2 == c**2 or b**2 + c**2 == a**2 or c**2 + a**2 == b**2:
#     print("La tam giac vuong lod")
# else:
#     print("Dell la tam giac vuong")

# # B6_40:
# a=float(input())
# b=float(input())
# c=float(input())
# if a+b>c and b+c>a and c+a>b:
#     print("YES")

# # B5_40:
# n=int(input())
# m=int(input())
# if n % m == 0:
#     print("YES")
# else:
#     print("NO")

# # B4_40:
# a=int(input("a = "))
# b=int(input("b = "))
# c=int(input("c = "))
# if a > 0 and b > 0 and c > 0:
#     print("Car ba laf ddeeuf soos duonwg")

# # B2_46:
# x=int(input())
# if x < 100:
#     print("M ddax nhaajp ddungs")
# else:
#     print("Soos cuar m nhaajp vafo quas lowns")

# # B4_46:
# def f(x, y):
#     if x > y:
#         return x**2
#     elif x == y:
#         return x+y
#     else:
#         return y**2
# # print(f(int(input()), int(input())))

# # B6_47:
# d_tb=float(input())
# if d_tb >= 8.0:
#     print("Gioi")
# elif d_tb >= 6.5 and d_tb <= 7.9:
#     print("Kha")
# else:
#     print("NGU VL")

# # B7_48:
# n=int(input())
# if n <= 50:
#     print(n*1678) #first period of usage
# elif n >= 51 and n <= 100:
#     print(50*1678 + (n-50)*1734) #second period of usage
# elif n >= 101 and n <= 200:
#     print(50*1678 + 50*1734 + (n-100)*2014) #third period of usage
# elif n >= 201 and n <= 300:
#     print(50*1678 + 50*1734 + 100*2014 + (n-200)*2536)
# elif n >= 301 and n <= 400:
#     print(50*1678 + 50*1734 + 100*2014 + 100*2536 + (n-300)*2834)
# else:
#     print(50*1678 + 50*1734 + 100*2014 + 100*2536 + 100*2834 + (n-400)*2927) #nth period of usage

# # PA0027:
# a, b, c, d = list(map(int, input().split()))
# if a in range(c, d) or b in range(c, d) or c in range(a, b) or d in range(a, b):
#     print("Co diem chung")
# else:
#     print("Khong co diem chung")

# # B4_49:
# p, q, r = list(map(int, input().split()))
# if p*q == r:
#     print("YES")
# else:
#     print("NO")

# # B5_49:
# m, n, k= list(map(int, input().split()))
# if len(str(m*n*k)) > 2 and (m*n*k) % 10 == 0:
#     print("YES")
# else:
#     print("NO")

# # PA0032:
# n = int(input())
# if n % 400 == 0 and n % 4 == 0:
#     print(366)
# elif n % 100 == 0:
#     print(365)
# else:
#     print(365)
# def check_year(n):
#     if n % 400 == 0 and n % 4 == 0:
#         return 366
#     elif n % 100 == 0:
#         return 365
#     else:
#         return 365
    
# n_year, n_month = list(map(int, input().split()))
# if check_year(n_year) == 366 and n_month == 2:
#     print(29)
# elif check_year(n_year) == 365 and n_month == 2:
#     print(28)
# elif n_month in [1, 3, 5, 7, 8, 10, 12]:
#     print(31)
# else:
#     print(30)

# n=int(input())
# days=0
# while n<=10**9:
#     n*=2
#     days += 1
# print(days)

# vòng lặp:
# VD:
# for x in range(0, 100, 2):
#     print(x)

# # PA0041 (NEEDS FINALIZATION):
# counter = 1
# for i in range(1, 10):
#     for i in range(counter, 101, 10):
#         print(i, end=' ')
#     print('\n')
#     counter += 1

# # PA0042:
# for i in range(100, 0, -1):
#     print(i, end=' ')

# n = int(input("n = "))
# for i in range(1, 11):
#     print(f"{n} x {i} =", n*i)

# n = int(input())
# for i in range(1, n+1):
#     if n % i == 0:
#         print(f"chia lam {i} phan moi phan co {n//i} chiec keo")

# # gcd_homemade: gồm 3 bài, in i nếu i là ước của n, đếm số ước của n, tính tổng các ước của n
# n=int(input())
# sum_common_divisors = 0
# counter = 0
# for i in range(1, n+1):
#     if n % i == 0:
#         print(i, end=' ') # In i nếu i là ước của n
#         counter += 1 # Đếm số ước của n
#         sum_common_divisors += i # Tính tổng các ước của n
# print(counter)
# print(sum_common_divisors)

# # TÍnh tổng 1+2+3+...+n
# sumz=0
# n=int(input("n="))
# for i in range(1, n+1):
#   sumz+=i
# print(sumz)

# sumz_2=0
# n=int(input('n='))
# for i in range(1, n**2):
#   sumz_2+=i**2
# print(sumz_2)

# sumz=0
# n=int(input('n='))
# for i in range(1, n+1):
#   sumz+=1/i
# print(sumz)

# sumz=0
# n=int(input('n='))
# for i in range(2, 2*n+1, 2):
#   sumz+=1/i
# print(sumz)

# sumz=0
# n=int(input('n='))
# for i in range(1, n+1):
#   sumz+=1/(i*(i+1))
# print(sumz)

# sumz=0
# n=int(input('n='))
# for i in range(2, n+2):
#   sumz+=i/(i+1)
# print(sumz)

# 9/1/26:
# # B1
# x, n=list(map(str, input().split()))
# print(x*int(n))

# # B2
# n = int(input())
# for i in range(1,n+1):
#     if i % 2 == 0:
#         print(i, end=' ') # OPTIMIZED

# # B3
# n=int(input())
# suz=0
# for i in range(n,0,-1):
#     if i % 2 != 0:
#         print(i)
#         suz+=i
# print(suz)

# # B4
# n=int(input()) 
# sum_n=0
# counter=0
# while n != 0:
#     sum_n += n%10
#     n//=10
#     counter+=1
# print(sum_n, counter)

# # B5 (làm thế này tiện hơn, dùng đệ quy) O(2^n)
# def factorial(n):
#     if n == 1:
#         return n
#     return n*factorial(n-1)
# print(factorial(int(input())))

# # B6 (đệ quy tiếp)
# def exponent(a, n):
#     if n == 1:
#         return a
#     return a * exponent(a, n-1)
# print(exponent(int(input()), int(input())))

# # B7
# n, m = list(map(int, input().split()))
# for i in range(n):
#     print("#" * m)

# # B8
# n = int(input())
# for i in range(n):

# # B1 _ onboard:
# for i in range(1, 11):
#     print(i, end=' ')

# # B9:
# n = int(input())
# for i in range(n):
#     print("*"*(n-i))

# # B13:
# N = int(input())
# for i in range(1, N+1):
#     if i % 2 == 0 and i%3 == 0:
#         print(i, end=' ')

# # B14 (kinda)
# N = int(input())
# sum_count=0
# for i in range(2, N):
#     if N % i == 0:
#         sum_count+=i
# if sum_count >= N:
#     print(1)
# else:
#     print(0)

# # B18
# n = int(input())
# true_counter=0
# counter=0
# while n != 0:
#     if n % 10 in [8, 6]:
#         true_counter+=1
#     n//=10
#     counter+=1
# if true_counter == counter:
#     print("YES")
# else:
#     print("NO")

# # B10
# def gcd_homemade(a, b):
#     if a == 0:
#         return b
#     return gcd_homemade(b%a, a)
# print(gcd_homemade(-36, -81))

# # B12
# def perfect_square_check(n):
#     perfect_squares=[]
#     perfect_squares_count=0
#     for i in range(1, n+1):
#         if int(math.sqrt(i))**2 == i:
#             perfect_squares_count+=1
#             perfect_squares.append(i)
#     return perfect_squares, perfect_squares_count
# print(perfect_square_check(int(input())))

# # B15:
# def reverse_number(a, b):
#     if int(str(a)[::-1]) > int(str(b)[::-1]):
#         return int(str(a)[::-1])
#     else:
#         return int(str(b)[::-1])
    
# print(reverse_number(123, 893))

# # B16
# def abundant_number(n):
#     common_divisors=0
#     for i in range(1, n):
#         if n%i == 0:
#             common_divisors+=i
#     if common_divisors > n:
#         return 1
#     else:
#         return 0
# for i in range(12, 945):
#     print(i, abundant_number(i))

# # B17
# def symmetric_number(n):
#     if str(n)[::-1] == str(n):
#         return "YES"
#     else:
#         return "NO"

# print(symmetric_number(100))

# # B19 # Finalized:
# def summation(n):
#     resut=0
#     while n != 0:
#         resut+=n%10
#         n//=10
#     return resut
# # print(summation(1234))
# n_input=int(input())
# while n_input >= 10:
#     n_input=summation(n_input)
# print(n_input)

# # B21 is improved version of B18
# n = int(input())
# def check_good_number(a):
#     true_counter=0
#     counter=0
#     while a != 0:
#         if a % 10 in [8, 6]:
#             true_counter+=1
#         a//=10
#         counter+=1
#     if true_counter == counter:
#         return True
#     else:
#         return False
# counter=0
# for i in range(n+1):
#     if check_good_number(n) == True:
#         counter+=1
# print(counter)

# # PA0077
# temperatures=list(map(float, input().split()))
# max_temperature=max(temperatures)
# min_temperature=min(temperatures)
# temperatures_under_10=[]
# for i in temperatures:
#     if i < 10.0:
#         temperatures_under_10.append(i)
# print(temperatures_under_10)
# print(min_temperature)
# print(max_temperature)

# # PA0078
# n=int(input())
# n_height=list(map(int, input().split()))
# n_height_sorted=[]
# n_height.sort()
# print(n_height)

# # B1_96
# elec_bills = list(map(int, input().split()))
# sum_elec_bills = 0
# for i in elec_bills:
#     sum_elec_bills+=i
# average=int(sum_elec_bills/12)
# print("Tổng:", sum_elec_bills)
# print("TBC:", average)
# months_more_elec=[]
# for j in range(len(elec_bills)):
#     if elec_bills[j] > average:
#         months_more_elec.append(j)
# for k in months_more_elec:
#     print(k, end=' ')

# Phiếu ;-;

# # B1:
# def print_days_in_month_and_year(month, year):
#     months_31_days=[1,3,5,7,8,10,12]
#     months_30_days=[4,6,9,11]
#     if year % 4 == 0 and year % 100 != 0 and month == 2:
#         return '29'
#     elif month == 2 and year % 4 != 0:
#         return '28'
#     elif month in months_31_days:
#         return '31'
#     else:
#         return '30'
# print(print_days_in_month_and_year(2, 2000))

# # B2
# for i in range(1, 100):
#     if i % 3 == 0:
#         print(i)

# # B3
# for i in range(1, 100):
#     if i % 2 == 0 and i % 3 == 0:
#         print(i)

# B4
# n=int(input())
# sum_count=0
# for i in range(n+1):
#     sum_count+=i
# print(sum_count)

# B5
# for i in range(2000, 3201):
#     if i % 7 == 0 and i % 5 != 0:
#         print(i, end=', ')

# # B6
# a = int(input())
# a_divisors = 0
# for i in range(1, a):
#     if a % i == 0:
#         a_divisors+=1
# print(a_divisors)

# # B7
# a, b = list(map(int, input().split()))
# # print(a, b)
# max_val=0
# if a > b:
#     max_val = a
# else:
#     max_val = b
# for i in range(1, max_val):
#     if a % i == 0 and b % i == 0:
#         print(i)

# B8


# B9
# list_positive_numbers=[]
# while True:
#     n = int(input())
#     if n == -1:
#         break
#     else:
#         list_positive_numbers.append(n)
#         n=0

# print(min(list_positive_numbers), max(list_positive_numbers), list_positive_numbers)

# # B10
# n=int(input())
# sum_n_digits=0
# while n != 0:
#     sum_n_digits += n%10
#     n//=10
# print(sum_n_digits)

# B11
# s=input()
# print(s.split()[0])

# # B12:
# s=input() # Nhập vào chuỗi s.

# s_uppercases_count=0
# s_lowercases_count=0
# s_numbers_count=0

# for i in s:
#     if i.isupper() == True: # KIểm tra xem i có in HOA hay không.
#         s_uppercases_count+=1
#     elif i.isnumeric() == True: # Kiểm tra xem i có phải là SỐ hay không.
#         s_numbers_count+=1
#     else: # Tất cả các th còn lại, hay chữ in thường.
#         s_lowercases_count+=1

# B14 (derived from B12)
# # print(s_uppercases_count, s_numbers_count, s_lowercases_count)
# if len(s) >= 6 and s_uppercases_count >= 1 and s_lowercases_count >= 1 and s_numbers_count >= 1: # Điều kiện của đề
#     print("Good password")
# else:
#     print("NOT good password")

# # B13
# s = input()
# s_numbers_sum=0
# # for i in s:
# #     if i.isnumeric() == True:
# #         s_numbers_sum+=int(i)
# s_split=s.split()
# # print(s_split)
# for i in s_split:
#     if i.isnumeric() == True:
#         s_numbers_sum += int(i)
# print(s_numbers_sum)

# # B15:
# a = int(input())
# a_root = int(sqrt(a))
# # print(a_root)
# if a_root**2 == a:
#     print("Is perfect square")
# else:
#     print("Not a perfect square")

# s = input()
# print(s[0])

# s = input()
# i_upper = 0
# i_lower = 0
# i_digit = 0
# for i in s:
#     if i.isdigit() == True: i_digit+=1
#     elif i.isupper() == True: i_upper+=1
#     else: i_lower+=1

# print(i_digit, i_lower, i_upper)

# s = input()
# sum_digit = 0
# for i in s:
#     if i.isdigit() == True: sum_digit += int(i)
# print(sum_digit)

# s = input()
# i_upper = 0
# i_lower = 0
# i_digit = 0
# for i in s:
#     if i.isdigit() == True: i_digit+=1
#     elif i.isupper() == True: i_upper+=1
#     else: i_lower+=1
# if i_upper > 1 and i_lower > 1 and i_digit > 1 and len(s) > 6:
#     print("Iz good password")
# else:
#     print("Iz NOT good password")

# a = int(input())
# a_root = int(sqrt(a))
# # print(a_root)
# if a_root**2 == a:
#     print(True)
# else:
#     print(False)

# s = input()
# s_splet=s.split(",")
# print(s_splet.sort())

# a = input()
# a_sum=0
# for i in range(1, 5):
#     a_factor = a*i
#     a_sum += int(a_factor)
# print(a_sum)

# n = list(map(int, input().split()))
# sum_n=0
# sum_n_positive=0
# positive_counts=0
# for i in n:
#     sum_n += i
#     if i > 0:
#         sum_n_positive+=i
#         positive_counts+=1
# print(sum_n_positive / positive_counts)
# print(sum_n / len(n))

# for i in range(len(n)):
#     if n[i] < 0:
#         print(i)
#         break

# n = list(map(int, input().split()))
# last_pos = 0
# for i in range(len(n)):
#     if n[i] > 0:
#         last_pos = i
# print(last_pos)

# # B1:
# for i in range(10, 201):
#     if i % 7 == 0 and i % 5 != 0:
#         print(i, end='; ')

# # B2:
# product = 1
# for i in range(1, int(input())+1):
#     product*=i
# print(product)
# # By recursion:
# def factorial(n):
#     if n == 0:
#         return 1
#     return n*factorial(n-1)

# diction = {}
# n = int(input())
# for i in range(1, n+1):
#     diction[i] = i*i
# print(diction)

# print(gcd_homemade(9, 15))
# print(lcm_homemade(6, 7))

# def check_prime(n):
#     for i in range(2, n):
#         if n % i == 0:
#             return False
#     return True

# n = int(input())
# for i in range(2, n):
#     if check_prime(i) == True:
#         print(i)

# # B6:
# n = int(input())
# for i in range(2, n+1):
#     if check_prime(i) == True:
#         print(i)

# # B7:
# n = int(input())
# for i in range(2, n+1):
#     if check_prime(i) == True and len(str(i)) == 5:
#         print(i)

# n = int(input())
# sum_digits = 0
# while n != 0:
#     sum_digits += n%10
#     n//=10
# print(sum_digits)

# n = int(input())
# if check_prime(n) != True:
#     print("NOT a prime number!")
# else:
#     for i in range(n+1):
#         print(fibonacci_procedure(i))

# B1:
# a, b, c = list(map(int, input().split()))
# if a - b == c:
#     print('-')
# else:
#     print('+')

# # B2:
# n, m, k = list(map(int, input().split()))
# if k % n == 0 or k % m == 0:
#     print("YES")
# else:
#     print("NO")

# # B3:
# n, k = list(map(int, input().split()))
# for a in range(1, k):
#     b = k - a
#     if a**b == n:
#         print(a, b)
#         mark = 1
#         break
#     else:
#         mark = 0
#         continue
# if mark == 0:
#     print(-1)

# B4
# propcasecompliant = input()
# if propcasecompliant[0].isupper() == True:
#     print(propcasecompliant[0].lower(),end='')
# for i in range(1, len(propcasecompliant)-1):
#     # print(i, propcasecompliant[i])
#     if propcasecompliant[i].isupper() == True:
#         print('_'+propcasecompliant[i].lower(), end='')
#     else:
#         print(propcasecompliant[i], end='')

# B5
# n, a, b = list(map(int, input().split()))
# list_n = list(map(int, input().split()))
# count_1 = 0
# count_2 = 0
# for i in range(len(list_n)):
#     if list_n[i] == 1:
#         count_1+=1
#     else:
#         count_2+=1
# if count_1 == a and count_2 == b:
#     exit()
# else:
#     print((count_1 + count_2) - (a+b))

# Đề 4:
# # B1:
# t, v, n, tc, kk, ut, tb = list(map(float, input().split()))
# xtn = ((((t+v+n+tc)+kk) / 4) + tb) / 2 + ut
# # print(xtn)
# if xtn > 5 and t>1 and v>1 and n>1 and tc>1:
#     print("DAT")
# else:
#     print("TRUOT")

# # B2:
# a = int(input())
# tong_ve = (a // 6)*5 + (a%6)
# print(tong_ve * 5000)

# n = int(input())
# strings_n = []
# for string in range(n):
#     strings_n.append(input())
# for i in range(n):
#     for j in range(len(strings_n[i])):
#         if strings_n[i][j].islower() == False:
#             trues = 0
#             if trues == 0 and strings_n[i][0].isupper() == False:
#                 print(i, end=' ')

# B1:
# a = int(input())
# print((a*10 // 5) * 4)

# # B2:
# h, p, s = list(map(int, input().split()))
# if s >= 59 and p >= 59:
#     h1 = h+1
#     p1 = 0
#     s1 = 0
# elif s >= 59 and p <= 58:
#     h1 = h
#     p1 = p+1
#     s1 = 0
# else:
#     h1 = h
#     p1 = p
#     s1 = s+1
# print(h1, p1, s1)

# # B3:
# a, b, c = list(map(int, input().split()))
# s = (a**b)**c + (b**a)**c - (c**a)**b
# print(s)

# # B4:
# s = input()
# max_chars = int(s[0])
# curr_chars = int(s[0])
# for i in range(2, len(s)):
#     if i % 2 != 0 and s[i] == s[i-2]:
#         # print(i, s[i], s[i-1], s[i-2])
#         curr_chars += int(s[i-1])
#     else:
#         curr_chars = int(s[i-1])
#     max_chars = max(max_chars, curr_chars)
# print(max_chars)

# # B5:
# n, k, p = list(map(int, input().split()))
# n_list = list(map(int, input().split()))
# for i in range()

# B1:
# a = int(input())
# b = int(input())
# c = int(input())
# d = [a, b, c]
# d.sort()
# max_num = float('inf')
# for i in range(len(d)):
#     for j in range(len(d)):
#         old_num = int(str(d[i])+str(d[i-1]))
#     max_num = min(max_num, old_num)
# print(max_num)

# a = int(input())
# b = int(input())

# a, b, c, x, y = list(map(int, input().split()))
# cow_sandwiches = x * (a//2 * b)
# chicken_sandwiches = y * ((a - a//2) // 2 * c)
# print(cow_sandwiches, chicken_sandwiches)

# n = int(input())
# a, b, c, d = list(map(int, input().split()))
# successive_list = [a, b, c, d]
# for i in range(n):
#     for j in range(n):
#         print(successive_list[j], successive_list[j-1])
#         successive_list.append(successive_list[j] + successive_list[j-1])
# print(successive_list)

# command_list = list(map(str, input().split()))
# x = 0
# y = 0
# for i in command_list:
#     # print(i)
#     if i == 'N':
#         y += 1
#     if i == 'W':
#         x -= 1
#     if i == 'E':
#         x += 1
#     if i == 'S':
#         y -= 1
#     print(x, y)

# n = int(input())
# a = list(map(int, input().split()))
# total_revenue = 0
# max_revenue = 0
# max_revenue_index = 0
# for i in range(len(a)):
#     total_revenue += a[i]
#     if a[i] > max_revenue:
#         max_revenue = a[i]
#         max_revenue_index = i

# print(total_revenue)
# print(max_revenue_index)

# Bài 1: DONE!
# sum_perfect_squares_odd = 0
# count_perfect_squares_odd = 0
# n = int(input())
# for i in range(1, n+1):
#     if int(math.sqrt(i))**2 == i and i % 2 != 0:
#         # print(i)
#         sum_perfect_squares_odd += i
#         count_perfect_squares_odd += 1
# print(count_perfect_squares_odd)
# print(sum_perfect_squares_odd)

# list_ordered = list(map(int, input().split()))
# target = int(input())
# print(binary_search(0, len(list_ordered)-1, list_ordered, target))

# # PARTIAL:
# a, b = list(map(int, input().split()))
# a_2, b_2 = list(map(int, input().split()))
# if a == a_2 and b != b_2:
#     print("Parallel")
# elif a == a_2 and b == b_2:
#     print("Coincident")
# else:
#     x = (b_2 - b) / (a - a_2)
#     y = a * x + b
#     print(f"Intersect {x} {y}")

# # Even numbers pairs:
# n = int(input())
# counts = 0
# for i in range(1, n+1):
#     for j in range(1, i+1):
#         if (i * j) % 2 == 0:
#             print(i, j) # Test
#             counts += 1
# print(counts)

# a, b, c = list(map(int, input().split()))
# m = int(input())
# max_product = max(a, b) * max(b,c)
# print(max_product)

# n = int(input())
# for a in range(1, n+1):
#     for b in range(1, n+1):
#         if a*b % 2 == 0:
#             print(a, b)

# n = int(input())
# if n > 2 and n % 2 == 0:
#     print("YES")
# else:
#     print("NO")

# s = list(map(str, input().split()))
# count = 0
# index_count = []
# for i in range(len(s)):
#     if s[i] == s[i][::-1]:
#         count += 1
#         index_count.append(s[i])
# print(count)
# # for index in index_count:
# #     print(index)
# print(*index_count)

# # B1: Time complexity: O(1)   
# a, n, k = list(map(int, input().split()))
# total_time = n*60 - a + k*5
# print(total_time)

# # B2:
# n, x = list(map(int, input().split()))
# n = math.ceil(n / 2)
# print(n*x)

# # B3:
# n = int(input())
# s = 0
# print(n * (n+1))

# # B4:
# dna_root = input()
# dna_augmented = ''
# for i in range(len(dna_root)):
#     if i % 2 == 0:
#         factor = int(dna_root[i])
#     else:
#         if s[i] == 'A':
#             dna_augmented += factor * "T"
#         elif s[i] == 'G'
# # TODO: repeat for other cases:

# Binary exponents:
def binary_exp(a, n):
    if n == 0: # Degenerate case:
        return 1
    res = binary_exp(a, n//2)
    if n % 2 == 1:
        return a*res*res
    return res*res

def binary_exp_mod(a, n, m): # use with m primes only!
    if n == 0: # Degenerate case:
        return 1
    res = binary_exp_mod(a, n//2, m)
    if n % 2 == 1:
        return a*res*res % m
    return res*res % m
# print(binary_exp(3, 3))
# print(sieve(int(input())))

# NOT efficient! See function's definition from line 993 - 1000
# print(fibonacci_procedure(int(input())) % 1000000007)

# # 6 july 2026:
# n, q = list(map(int, input().split()))
# a = list(map(int, input().split()))
# queues = []
# for i in range(q):
#     l, r = list(map(int, input().split()))
#     queues.append((l, r))
# for queue in queues:
#     sum_1 = 0
#     for j in range(queue[0], queue[1]+1):
#         sum_1 += a[j]
#     print(sum_1)

# # Collatz Conjecture / Giả thuyết Collatz:
# n = int(input())
# while n != 1:
#     if n % 2 == 1:
#         n = 3*n + 1
#     else:
#         n = n // 2
#     print(n, end=' ')

# n, W = list(map(int, input().split()))
# items = []
# for item in range(n):
#     w, v = list(map(int, input().split()))
#     items.append((w, v))

# n = int(input())
# a = list(map(int, input().split()))
# counter_strike = 0
# i = 0
# for i in range(n-1):
#     while a[i] > a[i+1]:
#         a[i+1] += 1
#         counter_strike += 1
# print(counter_strike)
#     print(counter_strike, a)        
# print(counter_strike, a)
    # print(a[i], a[i+1], a)

# # Simple enough:
# n = int(input())
# x = 0
# for _ in range(n):
#     statement = input()
#     if '--' in statement:
#         x-=1
#     if '++' in statement:
#         x+=1
# print(x)

# st_c = int(input())
# dict_scores = {}
# for _ in range(st_c):
#     name, score = list(map(str, input().split()))
#     dict_scores[name] = int(score)
# name_queues = []
# for _ in range(int(input())):
#     name_queues.append(input())
# for queue in name_queues:
#     print(dict_scores[queue])

# n, x = list(map(int, input().split()))
# numbers = list(map(int, input().split()))
# numbers.sort()
# flag_yes = False
# left = 0
# right = n-1
# while left < right:
#     tong = numbers[left] + numbers[right]
#     if tong == x:
#         flag_yes = True
#         print((left, right))
#         break
#     elif tong < x:
#         left += 1
#     else:
#         right -= 1
# if flag_yes == False:
#     print("IMPOSSIBLE")

# a = list(map(int, input().split()))
# b = list(map(int, input().split()))
# c = []
# left1 = 0
# left2 = 0
# while left1 <= len(a) or left2 <= len(b):
#     if left1 == len(a):
#         left2 += 1
#     elif left2 == len(b):
#         left1 += 1
#     elif a[left1] < b[left2]:
#         c.append(a[left1])
#         left1 += 1
#     else:
#         c.append(b[left2])
#         left2 += 1
# print(c)

# n, m, k = list(map(int, input().split()))
# ap_d_sizes = list(map(int, input().split()))
# ap_r_sizes = list(map(int, input().split()))
# l1 = 0
# l2 = 0
# count = 0
# while l1 < len(ap_d_sizes) and l2 < len(ap_r_sizes):
#     if ap_d_sizes[l1] < ap_r_sizes[l2] - k:
#         l1 += 1
#     elif ap_d_sizes[l1] > ap_r_sizes[l2] + k:
#         l2 += 1
#     else:
#         count += 1
#         l1 += 1
#         l2 += 1
# print(count)

# sys.setrecursionlimit(400000)

# mod = 1000000007

# def binary_exp_mod(a, n): # use with m primes only!
#     if n == 0: # Degenerate case:
#         return 1
#     res = binary_exp_mod(a, n//2)
#     if n % 2 == 1:
#         return (((res * res) % mod) * (a % mod)) % mod
#     return (res * res) % mod
# def factorial(max_n, cache):
#     cache[0] = 1
#     if max_n > 0:
#         cache[1] = 1
#     for i in range(2, max_n + 1):
#         cache[i] = (i * cache[i - 1]) % mod

# n = int(input())
# coffs = []
# max_n = 0
# for _ in range(n):
#     coff_pair = input().split()
#     coffs.append((int(coff_pair[0]), int(coff_pair[1])))
#     max_n = max((int(coff_pair[0]), max_n))

# factorials = [0] * (max_n+1)
# factorial(max_n, factorials)
# for pair in coffs:
#     n_v = pair[0]
#     k_v = pair[1]
#     top = factorials[n_v]
#     bot = (factorials[k_v] * factorials[n_v - k_v]) % mod
#     inv_bot = binary_exp_mod(bot, mod-2)
#     ans = (top * inv_bot) % mod
#     print(ans)
#     


# Preprocessing phase of
def sqrt_decomp_preprocessing(a):
    n = len(a)
    s = math.ceil(square_root_H(n))
    b = []

    for k in range(s):
        b_v = 0
        start = k*s
        end = min(n-1, (k+1) * s-1)
        for i in range(start, end+1):
            b_v += a[i]
        b.append(b_v)
        return b


# a = list(map(int, input().split()))
# n = len(a)
# s = math.ceil(square_root_H(n))
# b = []

# for k in range(s):
#     b_v = 0
#     start = k*s
#     end = min(n-1, (k+1) * s-1)
#     for i in range(start, end+1):
#         b_v += a[i]
#     b.append(b_v)
# # print(b)

# for i in range(1<<30):
#     print(i)

# n = int(input())
# g = list(map(int, input().split()))
# bubble_sort(g)
# print(g)
# print(binary_search(0, len(g), g, n))
# print(linear_search(0, g, n))