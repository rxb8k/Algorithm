N = int(input())
numbers = input().split()
sum = numbers[0]

for i in range(len(numbers)):
    if i > 0 and numbers[i] - numbers[i-1] == 1:
        sum += numbers[i]

print(sum)