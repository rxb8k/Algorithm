T=int(input())

for testcase in range(T):
    isAnagram=False
    words=input().split()
    word_a=str(words[0])
    word_b=str(words[1])

    sorted_a=sorted(list(word_a))
    sorted_b=sorted(list(word_b))
    
    if(sorted_a==sorted_b):
        isAnagram=True

    if(isAnagram==True):
        print(f'{word_a} & {word_b} are anagrams.')
    else:
        print(f'{word_a} & {word_b} are NOT anagrams.')