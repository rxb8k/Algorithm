bowls = input()
height = 10

for i in range(1, len(bowls)):
    if bowls[i-1] == bowls[i]:
        height += 5
    else:
        height += 10

print(height)