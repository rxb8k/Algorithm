N = int(input())
left_apple = 0

for n in range(N):
    student, apple = map(int, input().split())
    left_apple += apple % student

print(left_apple)