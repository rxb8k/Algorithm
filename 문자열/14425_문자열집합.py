N, M = map(int, input().split())
S = [input() for i in range(N)]
answer = 0

for i in range(M):
    test_word = input()

    if test_word in S:
        answer +=1

print(answer)