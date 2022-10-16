N=int(input())
first_letter=list(0 for i in range(26)) # 길이가 26이고, 값이 0으로 초기화된 리스트 생성
answer=''

for player in range(N):
    name=input()
    first_letter[ord(name[0])-ord('a')]+=1

for letter_index in range(26):
    if first_letter[letter_index]>=5:
        answer+=chr(ord('a')+letter_index)

if answer=='':
    answer='PREDAJA'

print(answer)