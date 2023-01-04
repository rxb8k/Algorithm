n = int(input())
cy = 100
sd = 100

for round in range(n):
    c, s = input().split()
    c = int(c)
    s = int(s)

    if c < s:
        cy = cy - s
    elif c > s:
        sd = sd - c

print(cy, sd)