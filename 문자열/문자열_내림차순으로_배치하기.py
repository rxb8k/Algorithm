def solution(s):
    s=list(s)
    s.sort(reverse=True) # 내림차순 정렬
    return ''.join(s)