name = input()
KMP_name = name[0]

for i in range(len(name)):
    if name[i] == '-':
        KMP_name += name[i+1]

print(KMP_name)