n = int(input())
moves = 0
x = list(map(int, input().split()))
for i in range(n-1):
    if x[i] > x[i+1]:
        moves += x[i] - x[i-1]
        x[i+1] = x[i]
print(moves)