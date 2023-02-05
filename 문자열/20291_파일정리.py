N = int(input())
type_dict = {}

for i in range(N):
    name, type = input().split('.')

    if type not in type_dict:
        type_dict[type] = 1
    else:
        type_dict[type] += 1

sorted_type_dict = sorted(type_dict.items()) ## 딕셔너리 내 아이템 정렬

for type, count in sorted_type_dict: # Key, value 출력
    print(type, count)