t=int(input())

for t in range(t):
    r, s=input().split() # 입력 받은 input을 공백 기준으로 split
    r=int(r)
    answer=''
    
    for i in range(len(s)):
        answer+=r*s[i]
    
    print(answer)