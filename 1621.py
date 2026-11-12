n = input()
inp = list(map(int, input().split()))
uniques = {}
for i in range(n):
    uniques.add(inp[i])

print(len(uniques))