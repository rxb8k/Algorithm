T=int(input())

for testcase in range(T):
    s=input()
    total_score=0
    score=0
    for i in range(len(s)):
        if s[i]=='O':
            score+=1
            total_score+=score
        else:
            score=0
    print(total_score)