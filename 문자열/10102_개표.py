v = int(input())
result = input()

a_score = result.count('A')
b_score = result.count('B')

if a_score > b_score:
    print('A')
elif b_score > a_score:
    print('B')
elif a_score == b_score:
    print('Tie')