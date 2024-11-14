import sys

input = sys.stdin.readline
INF = sys.maxsize

n = int(input())
m = int(input())
dist = [[INF] * (n + 1) for _ in range(n + 1)]

for i in range(1, n+1):
    for j in range(1, n+1):
        if i == j:
            dist[i][j] = 0

for _ in range(m):
    a, b, c = map(int, input().split())
    dist[a][b] = min(dist[a][b], c) # 노선이 하나가 아닐 수 있음. 최솟값 세팅.

#다이나믹
for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

for i in range(1, n+1):
    for j in range(1, n+1):
        if dist[i][j] == INF:
            print("0", end=" ")
        else:
            print(dist[i][j], end=" ")
    print()