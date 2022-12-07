N = int(input())
numbers = []

while N>0:
    numbers.append(N%10)
    N /= 10
    N = int(N)

numbers.sort(reverse=True) # 내림차순 정렬

for i in range(len(numbers)):
    numbers[i] = str(numbers[i])

print("".join(numbers))