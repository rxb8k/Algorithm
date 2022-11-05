from html.entities import name2codepoint


N=int(input())

for i in range(N):
    token_list=[]
    token_list=input().split()
    token_list[0]='god'
    print(str.join('', token_list))