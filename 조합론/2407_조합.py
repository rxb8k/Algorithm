def factorial (n):
    num = 1
    for i in range(2, n+1):
        num*=i
    return num

n, m = map(int, input().split())
print(factorial(n) // (factorial(m) * factorial(n-m)))