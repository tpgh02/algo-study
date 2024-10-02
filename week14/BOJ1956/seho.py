import sys

input = sys.stdin.readline

v, e = map(int, input().split())

dist = [[sys.maxsize for _ in range(v)] for _ in range(v)]

for _ in range(e):
    a, b, c = map(int, input().split())
    dist[a-1][b-1] = c

for node in range(v):
    for i in range(v):
        for j in range(v):
            dist[i][j] = min(dist[i][j], dist[i][node] + dist[node][j])

ans = sys.maxsize
for i in range(v):
    ans = min(ans, dist[i][i])

if ans == sys.maxsize :
    print(-1)
else:
    print(ans)