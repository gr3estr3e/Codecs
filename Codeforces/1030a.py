n = int(input())
flag = False
for i in range(n):
    a = sum(list(map(int, input().split())))
    if a != 0:
        flag = True
if flag != False: print("HARD")
else: print("EASY")