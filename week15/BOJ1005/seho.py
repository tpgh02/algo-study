import sys
from collections import deque
input = sys.stdin.readline

T = int(input())

for _ in range(T):
    n, m = map(int, input().split())
    cost = list(map(int, input().split()))
    ind = [0 for _ in range(n)]
    order = [[] for _ in range(n)]
    dq = deque([])
    dp = cost.copy()
    for _ in range(m):
        a, b = map(int, input().split())
        ind[b-1] += 1
        order[a-1].append(b-1)

    goal = int(input())-1

    for i in range(n):
        if ind[i] == 0 :
            dq.append(i)

    while len(dq) != 0 :
        idx = dq.popleft()
        for i in order[idx]:
            ind[i] -= 1
            if ind[i] == 0 :
                dq.append(i)
            dp[i] = max(cost[i] + dp[idx], dp[i])

    print(dp[goal])