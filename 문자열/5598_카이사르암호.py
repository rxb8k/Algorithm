input=input()
answer=''

for i in range(len(input)):
    letter_code=ord(input[i])
    if letter_code >= ord('A') and letter_code <= ord('C'):
        letter_code+=23
    else:
        letter_code-=3
    answer+=chr(letter_code)

print(answer)