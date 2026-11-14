n, k = list(map(int, input().split()))
a = list(map(int, input().split()))
kth_score = a[k-1]
count = 0
for i in range(n):
    if a[i] >= kth_score and a[i] > 0:
        count += 1
print(count)