n = int(input())

for testcase in range(n):
    p = int(input())
    max_cost = 0
    max_cost_player = ''

    for player in range(p):
        cost, name = input().split()
        if int(cost) >= max_cost:
            max_cost = int(cost)
            max_cost_player = name
            
    print(max_cost_player)