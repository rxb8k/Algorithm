def solution(s):
    answer = ''
    nums = s.split()
    
    min_num = float('inf')
    max_num = float('-inf')
    
    for n in nums:
        num = int(n)
        if num > max_num:
            max_num = num
        if num < min_num:
            min_num = num
    
    answer_list = [ str(min_num), str(max_num) ]
    answer = (' '.join(answer_list)) # 공백을 구분자로 하여 answer_list를 문자열로
    return answer