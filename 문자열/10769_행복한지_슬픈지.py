input = input()

happy = input.count(':-)')
sad = input.count(':-(')

if (happy+sad)==0:
    print('none')
elif happy == sad:
    print('unsure')
elif happy > sad:
    print('happy')
elif happy < sad:
    print('sad')