a = []
b = []

a.append(1)
b.append(0)

for i in range(1, 46):
    a.append(b[i-1])
    b.append(a[i-1] + b[i-1])

K = int(input())
print(a[K], b[K])