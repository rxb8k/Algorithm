vowel = ['a', 'e', 'i', 'o', 'u']
input = input()
cnt = 0

for i in input:
    if i in vowel:
        cnt += 1

print(cnt)