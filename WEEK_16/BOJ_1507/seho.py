import sys
input = sys.stdin.readline

n = int(input())
cost = []
for i in range(n):
    cost.append(list(map(int, input().split())))

def floyd():
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if i == j or i == k or j == k:
                    continue
                if cost[i][j] == cost[i][k] + cost[k][j]:
                    cost[i][j] = sys.maxsize
                elif cost[i][j] < cost[i][k] + cost[k][j]:
                    continue
                else:
                    if cost[i][j] != sys.maxsize:
                        return False
    return True

isTrue = floyd()
ans = 0
if isTrue:
    for i in range(n):
        for j in range(i+1, n):
            if cost[i][j] != sys.maxsize:
                ans += cost[i][j]
    print(ans)
else:
    print(-1)