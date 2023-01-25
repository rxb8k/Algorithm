import sys

def reverse(s):
    r = ''
    for i in range(len(s)-1, -1, -1):
        r += s[i]
    return r


T = int(input())

for t in range(T):
    s = sys.stdin.readline().split()
    r = [ reverse(token) for token in s ]

    print(' '.join(r))