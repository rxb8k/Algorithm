def solution(s):
    answer = ''
    tokens = s.split(' ')
    
    for token in tokens:
        for i in range(len(token)):
            if i % 2 == 0:
                answer += token[i].upper()
            else:
                answer += token[i].lower()
        answer += ' '
    
    return answer[:-1]