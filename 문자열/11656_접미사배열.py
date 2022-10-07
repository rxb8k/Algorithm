input=input()
word_list=[]

for i in range(len(input)):
    word_list.append(input[i:])

word_list.sort()

for word in word_list:
    print(word)