counter = 0
odds = -1
a = input()
restruct = ''
maps = [0] * 26
for i in range(len(a)):  
    maps[ord(a[i]) - ord('A')] += 1
for i in range(26):
    if maps[i] % 2 == 1:
        counter += 1
        odds = i
if counter >= 2:
    print("NO SOLUTION")
    quit()
for i in range(26):
    if i != odds:
        for j in range(maps[i] // 2):
            restruct += chr(i+ ord('A'))
if odds >= 0:
    for i in range(maps[odds]):
        restruct += chr(odds + ord('A'))
for i in range(25, 0, -1):
    if i != odds:
        for j in range(maps[i] // 2):
            restruct += chr(i+ord('A'))
print(restruct)