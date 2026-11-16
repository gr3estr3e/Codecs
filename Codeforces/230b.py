n = int(input())
a = list(map(int, input().split()))
marks = [True] * (n+1)
marks[0] = marks[1] = False

for i in range(2, n+1):
    if marks[i]:
        for j in range(i*i, n+1, i):
            marks[j] = False

for i in a:
    sqrti = int(i**0.5)
    if (sqrti * sqrti == i and marks[sqrti] != False):
        print("YES")
    else:
        print("NO")